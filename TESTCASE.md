# 📁 Manual Test Cases

## 🧪 Test Case 1: Create folder

**Input**

```
mkdir documents
ls
```

**✅ Expected Output**

```
Folder documents created.
docs
images
documents
```

## 🧪 Test Case 2: Rename folder

**Input**

```
rn documents app
ls
```

**✅ Expected Output**

```
Renamed documents to app
docs
images
app
```

## 🧪 Test Case 3: Rename non-exist folder

**Input**

```
rn documents app
ls
```

**✅ Expected Output**

```
documents does not exist.
docs
images
app
```

## 🧪 Test Case 4: Delete folder

**Input**

```
rm app
ls
```

**✅ Expected Output**

```
Deleted app
docs
images
```

## 🧪 Test Case 5: Delete non-exist folder

**Input**

```
rm app
ls
```

**✅ Expected Output**

```
app not exist.
docs
images
```

## 🧪 Test Case 6: Move file

**Input**

```
touch test.txt
mv test.txt docs
cd docs
ls
```

**✅ Expected Output**

```
File test.txt created.
Moved test.txt to docs
test.txt
intro.txt
tutorial.txt
```

## 🧪 Test Case 7: Move non-exist file

**Input**

```
mv file.txt test
```

**✅ Expected Output**

```
Item not found
```

## 🧪 Test Case 8: Copy file

**Input**

```
cp test.txt test3.txt
ls
```

**✅ Expected Output**

```
Copied test.txt as test3.txt
test.txt
test3.txt
intro.txt
tutorial.txt
```

## 🧪 Test Case 9: Copy non-exist file

**Input**

```
cp test5.txt test10.txt
```

**✅ Expected Output**

```
Item test5.txt not found.
```

## 🧪 Test Case 10: Write file

**Input**

```
nano test.txt
This is new content of test.txt
::end
cat test.txt
```

**✅ Expected Output**

```
test.txt updated.
This is new content of test.txt
```

## 🧪 Test Case 11: Write non-exist file

**Input**

```
nano test10.txt
```

**✅ Expected Output**

```
test10.txt not found.
```

## 🧪 Test Case 12: View file

**Input**

```
cat intro.txt
```

**✅ Expected Output**

```
Welcome to the documentation!
This file contains the introduction.
```

## 🧪 Test Case 13: View non-exist file

**Input**

```
cat test10.txt
```

**✅ Expected Output**

```
test10.txt not found.
```

## 🧪 Test Case 14: navigate directory back

**Input**

```
cd ..
ls
```

**✅ Expected Output**

```
Home>
docs images
```

## 🧪 Test Case 15: navigate directory

**Input**

```
cd docs
ls
```

**✅ Expected Output**

```
test.txt
test3.txt
intro.txt
tutorial.txt
```

## 🧪 Test Case 16: navigate non-exist directory

**Input**

```
cd abc
```

**✅ Expected Output**

```
Home/docs>
```

## 🧪 Test Case 17: Display working directory

**Input**

```
pwd
```

**✅ Expected Output**

```
Path
----
Home/docs
```

## 🧪 Test Case 18: Return to root

**Input**

```
home
```

**✅ Expected Output**

```
Home>
```

## 🧪 Test Case 19: Search exist file

**Input**

```
search tutorial.txt
```

**✅ Expected Output**

```
Home/docs>
```

## 🧪 Test Case 20: Search non-exist file

**Input**

```
search test.txt
```

**✅ Expected Output**

```
File/Folder does not exist.
```

## 🧪 Test Case 21: Helper command

**Input**

```
help
```

**✅ Expected Output**

```
mkdir   Create folder.
touch   Create file.
rn      Rename directory.
rm       Remove directory.
mv      Move directory.
cp      Duplicate directory.
nano    Edit file.
cat     View file content.
cd      Change the current directory.
ls      Display the current directory.
pwd     Display the current directory.
home    Quickly return to root directory.
search  Find specific file/folder by name.
exit    Terminate program.
```

## 🧪 Test Case 22: Close program

**Input**

```
exit
```

**✅ Expected Output**

```
// Program must be closed.
```
