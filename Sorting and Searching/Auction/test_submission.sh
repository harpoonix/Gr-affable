echo "Submission Checker"

# Can be used to check all submissions 
# Add path to testing .cpp file to generate an executable
g++ rohankalbag_auction1.cpp -o executable 

rm -rf -f Test\ Cases\ Generated #Create a Folder for Generated Testcases
mkdir Test\ Cases\ Generated

for i in {1..7} #Replace 7 with number of testcases
# replace 3s with time to check if Time Limit Exceeded
do
    timeout 3s ./executable < Test\ Cases/input$i.txt > Test\ Cases\ Generated/test_output$i.txt || echo "### Testcase '${i}' Time Limit Exceeded ###"
    cmp --silent Test\ Cases/output$i.txt Test\ Cases\ Generated/test_output$i.txt && echo '### SUCCESS: Testcase '${i}' Passed! ###' || echo '### WARNING: Testcase '${i}' Failed! ###'
done

rm -rf -f Test\ Cases\ Generated #Delete Generated Testcases
echo "Testing Completed"

#Created with <3 by Rohan (github.com/rohankalbag)