# Editorial of [Jadoo and DNA Transcription](https://www.hackerearth.com/practice/python/getting-started/input-and-output/practice-problems/golf/jadoo-and-dna-transcription/description/)

* As the problem is very easy, the tricky part of the problem is to implement the solution in `<= 103` bytes i.e. the total number of characters present in the source-code should not exceed `103`.

* I have implemented the solution in `95` bytes which you can refer to in the file `transform_string.py`.

* In this article, I am going to explain the source-code line by line to make it easy for you to follow.

```Python
b=input() # Reading the string from the stdin stream.
try:print("".join(["UGCA"["ACGT".index(i)]for i in b]))
except:print("Invalid Input")
```

* Before explaination of the source-code, I highly suggest you read the [documentation](https://www.programiz.com/python-programming/methods/string/index) of `ndex()` in string class in python.

* `print("".join(["UGCA"["ACGT".index(i)]for i in b]))`. In this part of the source-code, I am using list-comprehension to build a list of replaced-characters, means for every character in the string `b`, I am finding whether that character is present in the string `ACGT`, if present `index()` returns the index (zero-based) of that character in the string `ACGT` then I am checking the value stored at the index (returned by the `index()`) in string `UGCA` and whatever the value present at the index in the string `UGCA` will be the part of the list created using list-compreshension. Then I am joining the characters present in the list using the `join()`.
