# RSA and Huffman Compression

The trial runs for our self-driving car are gaining momentum, and everything seems to be going great. But every now and then, there are some system failures and bugs that you need to report back to your technical headquarters so they can work on a fix. Communication between the car and the coding team back home is key to delivering updates.

Unfortunately, your project has taken the backseat in allocation of funds, losing out to bigger players. The supported bandwidth for your communication channel is quite low, and cannot realiably send huge system logfiles without corruption of contents. On top of that, rival companies are trying to sabotage your runs by sending forged logfiles, pretending like they came from the car.

You decide to tackle both of these issues. You decide to encrypt your logfiles when you send them, but that won't solve the issue. We usually do not encrypt huge files with something like RSA, because that tends to be slow. Instead, we establish a secure connection, verify the identity of the senders through digital signatures, and revert to some form of simple symmetric encryption. You can click on the links to learn more about these fascinating topics.

For now, you only need to implement a simple RSA based digital signature. The can take a short string of text, encrypt it using its private key, and send it to the team. You can then decrypt it and verify that the corresponding logfiles have indeed originated from the car, and not from someone else.

To compress the logiles and make them small enough to be sent quickly and reliably, you can use the Huffman Compression Scheme. Basically, you encode the file in a way that saves you space, while making it absolutely clear what the decoded text will look like. You can get started with the concept of Huffman Encoding [here](https://www.youtube.com/watch?v=JsTptu56GM8).  

