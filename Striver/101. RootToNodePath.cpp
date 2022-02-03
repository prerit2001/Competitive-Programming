/*https://www.interviewbit.com/problems/path-to-given-node/*/
bool getPath(node * root, vector < int > & arr, int x) {
  if (!root)
    return false;

  arr.push_back(root -> data);

  if (root -> data == x)
    return true;

  if (getPath(root -> left, arr, x) || getPath(root -> right, arr, x))
    return true;

  arr.pop_back();
  return false;
}