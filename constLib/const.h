//
// Created by f2561 on 24-11-9.
//

#ifndef DADS_CONST_H
#define DADS_CONST_H
/**
<table>
    <tr>
        <th>Decimal</th>
        <th>Hexadecimal</th>
        <th>Character</th>
        <th>Description</th>
        <th>Type</th>
    </tr>

    <!-- Control Characters (0-31 and 127) -->
    <tr><td>0</td><td>0x00</td><td>&#0;</td><td>NUL (null)</td><td class="control">Control</td></tr>
    <tr><td>1</td><td>0x01</td><td>&#1;</td><td>SOH (start of heading)</td><td class="control">Control</td></tr>
    <tr><td>2</td><td>0x02</td><td>&#2;</td><td>STX (start of text)</td><td class="control">Control</td></tr>
    <!-- (省略其他控制字符，請按此格式添加更多) -->
    <tr><td>127</td><td>0x7F</td><td>&#127;</td><td>DEL (delete)</td><td class="control">Control</td></tr>

    <!-- Printable Characters: Symbols, Numbers, Uppercase, Lowercase -->

    <!-- Symbols (32-47) -->
    <tr><td>32</td><td>0x20</td><td>&nbsp;</td><td>Space</td><td class="printable">Printable</td></tr>
    <tr><td>33</td><td>0x21</td><td>!</td><td>Exclamation mark</td><td class="printable">Printable</td></tr>
    <tr><td>34</td><td>0x22</td><td>&quot;</td><td>Quotation mark</td><td class="printable">Printable</td></tr>
    <!-- (省略其他符號字符，請按此格式添加更多) -->

    <!-- Numbers (48-57) -->
    <tr><td>48</td><td>0x30</td><td>0</td><td>Digit 0</td><td class="printable">Printable</td></tr>
    <tr><td>49</td><td>0x31</td><td>1</td><td>Digit 1</td><td class="printable">Printable</td></tr>
    <!-- (省略其他數字字符，請按此格式添加更多) -->

    <!-- Uppercase Letters (65-90) -->
    <tr><td>65</td><td>0x41</td><td>A</td><td>Uppercase A</td><td class="printable">Printable</td></tr>
    <tr><td>66</td><td>0x42</td><td>B</td><td>Uppercase B</td><td class="printable">Printable</td></tr>
    <!-- (省略其他大寫字母，請按此格式添加更多) -->

    <!-- Lowercase Letters (97-122) -->
    <tr><td>97</td><td>0x61</td><td>a</td><td>Lowercase a</td><td class="printable">Printable</td></tr>
    <tr><td>98</td><td>0x62</td><td>b</td><td>Lowercase b</td><td class="printable">Printable</td></tr>
    <!-- (省略其他小寫字母，請按此格式添加更多) -->

    <!-- Symbols (123-126) -->
    <tr><td>123</td><td>0x7B</td><td>{</td><td>Left curly brace</td><td class="printable">Printable</td></tr>
    <tr><td>124</td><td>0x7C</td><td>|</td><td>Vertical bar</td><td class="printable">Printable</td></tr>
    <!-- (省略其他符號字符，請按此格式添加更多) -->
</table>

 */
const char ASCII_CHAR_ARRAY[] = {
        '\0', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07',
        '\x08', '\x09', '\x0A', '\x0B', '\x0C', '\x0D', '\x0E', '\x0F',
        '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
        '\x18', '\x19', '\x1A', '\x1B', '\x1C', '\x1D', '\x1E', '\x1F',
        ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?',
        '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
        'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_',
        '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
        'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', '\x7F'
};
#endif //DADS_CONST_H
