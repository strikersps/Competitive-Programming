import java.util.*;
import java.io.*;

class multipleOfThree {
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }

    public static void main(String[] args) throws IOException {
        Reader in = new Reader();
        int test = in .nextInt();
        while (test-- > 0) {
            long k = in .nextLong();
            long d0 = in .nextInt(), d1 = in .nextInt();
            String D2 = d0 + "" + d1 + "" + ((d0 + d1) % 10);
            long d2 = Integer.parseInt(D2);
            if (k == 2 || ((d0 + d1) % 10) == 0) {
                if (((d0 + d1) % 3) == 0) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
                continue;
            }
            long sum_of_digit = d0 + d1 + ((d0 + d1) % 10);
            if(k > 3) {
                long digit_repeat[] = {((d0 + d1) << 1) % 10, ((d0 + d1) << 2) % 10, ((d0 + d1) << 3) % 10, ((d0 + d1) << 4) % 10};
                long sum_digit_repeat = digit_repeat[0] + digit_repeat[1] + digit_repeat[2] + digit_repeat[3];
                sum_of_digit += (((k - 3) / 4) * (sum_digit_repeat));
                int remainder = (int) ((k - 3) % 4);
                switch (remainder) {
                    case 1:
                        sum_of_digit += digit_repeat[0];
                        break;
                    case 2:
                        sum_of_digit += (digit_repeat[0] + digit_repeat[1]);
                        break;
                    case 3:
                        sum_of_digit += (digit_repeat[0] + digit_repeat[1] + digit_repeat[2]);
                }
            }
            if((sum_of_digit % 3) == 0) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
