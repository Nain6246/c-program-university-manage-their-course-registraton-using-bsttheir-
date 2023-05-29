#include <iostream>
using namespace std; int course_1;
class BST
{
   BST *left, *right;
   int student_roll;
   int course_code;
   bool enrolled_course_1;
  

public:
   BST()
   {
      student_roll = 0;
      course_code = 0;
      course_1 = 0;
      left = NULL;
      right = NULL;
   }
   BST(int code, int roll_1)
   {
      student_roll = roll_1;
      course_code = code;
      course_1 += 1;
      enrolled_course_1 = true;

      left = NULL;
      right = NULL;
   }
   BST *insert(BST *root, int code, int roll)
   {
     
      if (root == NULL)
         return new BST(code, roll);
 if (course_1 == 50)
      {
         std::cout << "Course is alredy full you can`t enrolled in course1_1" << endl;
         return NULL;
      }
      if (code > root->course_code)
         root->right = insert(root->right, code, roll);
      else if (code < root->course_code)
         root->left = insert(root->left, code, roll);
      return root;
   }

   BST *search(BST *root, int key)
   {

      if (root == NULL || root->course_code == key)
         return root;

      if (root->course_code < key)
         return search(root->right, key);

      return search(root->left, key);
   }
   void in_order(BST *root)
   {
      if (root != NULL)
      {
         in_order(root->left);
         std::cout << root->student_roll << "\t" << root->course_code << " \t" << course_1 << "\t" << root->enrolled_course_1 << endl;
         in_order(root->right);
      }
   }
   void droup_course_by_code(int id, BST *root)
   {
      BST *temp = search(root, id);
      course_1 -= 1;
      temp->enrolled_course_1 = false;
   }

   void enroll_course(int id, BST *root)
   {
      BST *temp = search(root, id);
     course_1 += 1;
      temp->enrolled_course_1 = true;
   }

   void check_full()
   {
      if (course_1 == 50)
      {
         std::cout << "Coures is fully you cant enroll in course_1 " << endl;
      }
      else
      {
         std::cout << "ENrolled Successfully in course_1" << endl;
      }
   }

   int height(BST *root)
   {
      if (root == NULL)
      {
         return 0;
      }
      else
      {
         int left_side = height(root->left);
         int right_side = height(root->right);
         if (left_side > right_side)
         {
            return (left_side + 1);
         }
         else
         {
            return (right_side + 1);
         }
      }
   }

   BST *min_value_address(BST *root)
   {
      BST *current = root;
      while (current->left != NULL)
         current = current->left;
      return current;
   }

   void delete_whole_BST(BST *root)
   {
      if (root != NULL)
      {
         delete_whole_BST(root->left);
         delete_whole_BST(root->right);
         delete root;
      }
   }
   BST *delete_node(BST *root, int element)
   {

      if (root == NULL)
         return root;
      if (element < root->course_code)
         root->left = delete_node(root->left, element);
      else if (element > root->course_code)
         root->right = delete_node(root->right, element);
      else
      {
         if (root->left == NULL && root->right == NULL)
         {
            return NULL;
         }
         else if (root->left == NULL)
         {
            BST *temp = root->right;
            delete root;
            return temp;
         }
         else if (root->right == NULL)
         {
            BST *temp = root->left;
            delete root;
            return temp;
         }
         BST *temp = min_value_address(root->right);
         root->course_code = temp->course_code;
         root->right = delete_node(root->right, temp->course_code);
      }
      return root;
   }
};

int main()
{
   int element;
   BST b, *root = NULL;
   root = b.insert(root, 200, 50);

   for (;;)
   {
      std::cout << "1 insert record" << endl;
      std::cout << "2 delete record" << endl;
      std::cout << "3 search record" << endl;
      std::cout << "4 display record" << endl;
      std::cout << "5 enroll  course " << endl;
      std::cout << "6 drop course " << endl;
      std::cout << "7 Exit" << endl;
      std::cout << "Enter choice :";
      int choice;
      std::cin >> choice;
      if (choice == 1)
      {
         int code, roll;
         std::cout << "Enter code no ";
         std::cin >> code;
         std::cout << "Enter roll ";
         std::cin >> roll;
         b.insert(root, code, roll);
      }
      else if (choice == 2)
      {
         int elsemt;
         std::cout << "Enter roll no ";
         std::cin >> elsemt;
         b.delete_node(root, elsemt);
      }
      else if (choice == 3)
      {
         int elsemt;
         std::cout << "Enter roll no ";
         std::cin >> elsemt;
         b.search(root, elsemt);
      }
      else if (choice == 4)
      {
         std::cout << "roll\tcourse_code \tcourse_1 \tenrolled_course_1" << endl;

         b.in_order(root);
      }
      else if (choice == 5)
      {
         int elsemt;
         std::cout << "Enter roll no ";
         std::cin >> elsemt;
         b.enroll_course(elsemt, root);
      }
      else if (choice == 6)
      {
         int elsemt;
         std::cout << "Enter roll no ";
         std::cin >> elsemt;

         b.droup_course_by_code(elsemt, root);
      }
      else if (choice == 7)
      {
         break;
      }
      else
      {
         cout << "INVALID CHOICE " << endl;
      }
   }

   return 0;
}
