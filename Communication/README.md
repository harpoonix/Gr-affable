# RSA and Huffman Compression

The trial runs for our self-driving car are gaining momentum, and everything seems to be going great. But every now and then, there are some system failures and bugs that you need to report back to your technical headquarters so they can work on a fix. Communication between the car and the coding team back home is key to delivering updates.

Unfortunately, your project has taken the backseat in allocation of funds, losing out to bigger players. The supported bandwidth for your communication channel is quite low, and cannot realiably send huge system logfiles without corruption of contents. On top of that, rival companies are trying to sabotage your runs by sending forged logfiles, pretending like they came from the car.

You decide to tackle both of these issues. You decide to encrypt your logfiles when you send them, but that won't solve the issue. We usually do not encrypt huge files with something like [RSA](https://drive.google.com/file/d/1-b-v0p2JQWum2Huk2Hp-UADEZ3D9MNOB/view)(credits: [CSeC](https://github.com/CSecIITB)), because that tends to be slow. Instead, we establish a secure connection, verify the identity of the senders through [digital signatures](https://www.youtube.com/watch?v=s22eJ1eVLTU), and revert to some form of simple symmetric encryption. You can click on the links to learn more about these fascinating topics.

## Huffman Coding

To compress the logiles and make them small enough to be sent quickly and reliably, you can use the Huffman Compression Scheme. Basically, you encode the file in a way that saves you space, while making it absolutely clear what the decoded text will be, without prefix ambiguities. You can get started with the concept of Huffman Coding [here](https://www.youtube.com/watch?v=JsTptu56GM8).

Structure for the code is provided in the 'Huffman Codes' folder, to help you get started.

## Digital Signatures and RSA

For now, you only need to implement a simple RSA based digital signature. The car can take a short string of text, encrypt it using its private key, and send it to the team. You can then decrypt it and verify that the corresponding logfiles have indeed originated from the car, and not from someone else.

### Messages to integer

Text messages on their own cannot be encrypted since they are made of characters, a non numerical concept. So an encoding is used, most commonly Unicode or ASCII, to convert the given string to a sequence of bytes in hex-notation. Each character can be mapped to a 2 digit hex number. The resulting hex numbers can be concatenated, and the resulting number can be encrypted through modular exponentiation, like it is described [in the pdf](https://drive.google.com/file/d/1-b-v0p2JQWum2Huk2Hp-UADEZ3D9MNOB/view) and [on SE](https://crypto.stackexchange.com/questions/3617/how-do-ciphers-change-plaintext-into-numeric-digits-for-computing).

Alternatively, you can map each alphabet to a 2-digit number in base 10, starting with `00` for `A`, `01` for `B` and so on. This is less exhaustive compared to Unicode, but you can get it to work on alphanumeric signatures only.

### Exponentiation

The resulting message $M$ can be a huge integer, and we have to take the remainder when it is raised to the power of the public exponent, $e$. The numbers being dealt with here can get pretty massive. CS101 comes to the rescue. Implement the **fast exponentiation** technique from CS101, calculating exponent through repeated *squaring*, and using the property $AB \equiv (A \mod N)(B \mod N) \mod N$.

### Computing the private exponent

If you read up on RSA, you would know the private exponent is the inverse modulo $\phi(n)$ of $e$, or $$de \equiv 1 \mod \phi(N) = (p-1)(q-1) \text{(why?)}$$

Inverse modulus of $e$ can be found using the **Extended Euclidean Algorithm**.

$$de = qN + 1 \implies (-q)\cdot N + d\cdot e = 1 = \operatorname{gcd}(N, e)$$

The coefficients $(-q)$(not useful currently) and $d$ (useful) can be computed using Extended Euclid's ALgorithm.

You can check out this [awesome paper](https://www.nku.edu/~christensen/the%20mathematics%20of%20the%20RSA%20cryptosystem.pdf) for lucid explanation on the fascinating mathematics behind RSA.
