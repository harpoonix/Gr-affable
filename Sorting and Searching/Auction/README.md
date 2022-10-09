# Auction

The Gr-Affables presents you a Mega Auction where $n$ number of distinct technical gadgets/devices are at stake for $m$ number of buyers. But, they are all in a Blackbox to the buyers, no one knows what all devices are there but we ensure that they all are devices of cool technical utilities. Each device has a price associated with it for this auction, rules are a bit different and straight forward though. The customers come in a order, one by one. Each customer first announces the price that they are willing to pay for a device and then they will get the device with the price nearest to possible price told by customer such that it does not exceeds the price told by them. That's it, Sold!

## Instructions
- A file ``auction.cpp`` is given in this same directory. It has the solution for this problem, but the solution is not working correctly for some inputs and is also inefficient. The time complexity of that solution is $\mathcal{O}(mn)$ and still its implementation is not correct. Can you think of another solution that is first of all 'Correct' and furthermore better in efficiency. 
1. Basic - Modify the ``auction.cpp`` to achieve the correct solution for the problem. Upload your code as ``<your_GitHub_Username>_auction1.cpp``
2. More - If you can implement the solution in more efficient ways, do submit that as ``<your_GitHub_Username>_auction2.cpp>`` and justify your time complexity in your code.
   - For better approach, you may sort the devices based in prices. Search for the maximum price announced by a customer for upper bound. Print it and erase it from the auction list.
   - You can choose any efficient sorting algorithm you want. Using multisets is also a easy and nice way to do this.
   - If you think of another good idea, please show it off with your code.

### Input
- First line consists of two integers $n$ and $m$, the number of devices at auction and number of customers interested in buying them
- The next line provides $n$ integers representing the price of each ticket
- The last line provies $m$ integers representing the maximum price told by each customer in the order they arrive.

### Output
Print the price for each customer that he will pay for the device he gets. Note that once a device is sold, it cannot be purchased again.
There can be a condition where a customer may come empty handed from the auction, print ``-1`` for the poor soul

### Sample Input
```
5 3
7 3 5 8 5
4 8 3
```
### Sample Output
```
3 8 -1
```
