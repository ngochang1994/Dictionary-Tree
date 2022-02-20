// Function to create a new node
struct dictNode *
createANewNode ()
{
  struct dictNode *node = new dictNode;

  node->isWord = false;


  for (int i = 0; i < NUMOfCHARS; i++)
    {
      node->next[i] = NULL;
    }



  return node;
}

/*************************************************/


// Function to ignore case sensitivity
int
indexOfChar (char ch)
{
  int index;

  if (ch == '\'')
    {
      index = NUMOfCHARS - 1;
    }
  else if (ch >= 'A' && ch <= 'Z')

    {
      index = ch - 'A';
    }
  else
    {
      index = ch - 'a';
    }
  return index;

}





/**************************************************/


// Function to insert word to dictionary tree
void
insertWords2Dictionary (struct dictNode *dictnode, string str)
{
  struct dictNode *current = dictnode;


  for (int i = 0; i < str.size (); i++)
    {
      int index = indexOfChar (str[i]);	// Call indexOfChar

      if (!current->next[index])
	{
	  // Create a new node if the current node does not exist
	  current->next[index] = createANewNode ();
	}

      // Go to the next node
      current = current->next[index];
    }

  // Mark current node
  current->isWord = true;
}



/**************************************************/



// Function to count the words searched in the text file
int
countWordsStartingFromANode (int &result, struct dictNode *dictnode)
{
  if (dictnode->isWord)
    {
      result = result + 1;
    }


  for (int i = 0; i < NUMOfCHARS; i++)
    {
      if (!dictnode->next[i])
	{
	  // If a node is NULL, move to the next index
	  continue;
	}
      else
	{
	  countWordsStartingFromANode (result, dictnode->next[i]);
	}
    }

}



/**************************************************/



// Function to search words from the test file
bool
findEndingNodeOfAStr (struct dictNode *dictnode, string str)
{
  struct dictNode *current = dictnode;


  int result = 0;		//Declare the number of words counted


  for (int i = 0; i < str.size (); i++)
    {
      int index = indexOfChar (str[i]);	// Call indexOfChar

      if (current->next[index] == NULL)
	{

	  // If a node does NOT exist --> There's no further word
	  current = NULL;
	  break;
	}
      else
	{
	  current = current->next[index];
	}


    }


  if (current != NULL)		// If current is searched, call countWord to count words starting from that prefix
    {
      countWordsStartingFromANode (result, current);
      cout << str << " " << result << "\n";	// Output the number of words
    }

  else
    {
      cout << str << " " << result << "\n";
    }

}
