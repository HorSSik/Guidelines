#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>

class ConvertToUkrainian {
public: 
	bool check = false;
	char* ConvertToUa(long long int x) 
{
	char arr[1000];
	char *ukr = arr;
	const char *c[] = { "","����","���","���","������","�'���","�����","��","���","���'���","������", "����������", "����������","����������","������������","�'���������","�����������","���������","����������", "���'���������" };
	const char *d[] = { "��������","������","������","�����","���������","�'����","������","������","�������","���'����","�������", };
	const char *des[] = { " "," ","���������","���������","���������","�'����������","������������","�����������","�������������","���'�������", "" };
	const char *dec[] = { " "," ","��������","��������","�����","�'�������","���������","�������","��������","���'������", "" };
	const char *sot[] = { " ","�����","���������","����������","�������������","�'��������","���������","���������","�����������","���'��������", "" };
	const char *sog[] = { " ","���","����","������","���������","�'������","�������","�����","������","���'�����", "" };
	const char *thou[] = { "","����","����","�����","��������","�'���","�����","����","������","���'���","������", "����������", "����������","����������","������������","�'���������","�����������","���������","����������", "���'���������" };
	const char *thous[] = { " ","������","��������","��������","������","�'��������","����������","��������","������������","���'������" };
	if (x <= 10) {
		ukr += sprintf(ukr, "%s ", d[x]);
		return _strdup(arr);
	}
	if (x >= 1000000000000) {
		long long int h = x;
		check = true;
		if ((h % 1000000000000) == 0) {
			x /= 1000000000000;
			if (x >= 100 && x <= 999) {
				int j = x;
				x /= 100;
				ukr += sprintf(ukr, "%s ", sog[x]);
				if ((j %= 100) == 0) {
					ukr += sprintf(ukr, "�����������");
					j = 0;
					x = 0;
				}
				if (j >= 20 && j <= 99) {
					int Full = j / 10;
					int Ost = j % 10;
					ukr += sprintf(ukr, "%s ", thous[Full]);
					ukr += sprintf(ukr, "%s ", thou[Ost]);
					ukr += sprintf(ukr, "�����������");
					j = 0;
					x = 0;
				}
				if (j >= 1 && j <= 19) {
					if (j == 1) {
						ukr += sprintf(ukr, "%s ", thou[j]);
						ukr += sprintf(ukr, "�����������");
						return _strdup(arr);
					}
					else {
						ukr += sprintf(ukr, "%s ", thou[j]);
						ukr += sprintf(ukr, "�����������");
					}
					j = 0;
					x = 0;
				}
			}
			if (x >= 20 && x <= 99) {
				int Full = x / 10;
				int Ost = x % 10;
				ukr += sprintf(ukr, "%s ", thous[Full]);
				ukr += sprintf(ukr, "%s ", thou[Ost]);
				ukr += sprintf(ukr, "�����������");
				x = 0;
			}
			if (x >= 1 && x <= 19) {
				if (x == 1) {
					ukr += sprintf(ukr, "%s ", thou[x - 1]);
					ukr += sprintf(ukr, "�����������");
					return _strdup(arr);
				}
				else {
					ukr += sprintf(ukr, "%s ", thou[x]);
					ukr += sprintf(ukr, "�����������");
				}
				x = 0;
			}
		}
		else {
			h /= 1000000000000;
			long long int q = h;
			if (q >= 100 && q <= 999) {
				q /= 100;
				ukr += sprintf(ukr, "%s ", sog[q]);
				h %= 100;
			}
			if (h >= 20 && h <= 99) {
				int Full = h / 10;
				int Ost = h % 10;
				if (Ost == 1) {
					ukr += sprintf(ukr, "%s ", dec[Full]);
					ukr += sprintf(ukr, "���� ");
					ukr += sprintf(ukr, "�������� ");
				}
				if (Ost >= 2 && Ost <= 4) {
					ukr += sprintf(ukr, "%s ", dec[Full]);
					ukr += sprintf(ukr, "%s ", c[Ost]);
					ukr += sprintf(ukr, "��������� ");
				}
				if (Ost >= 5 && Ost <= 99) {
					ukr += sprintf(ukr, "%s ", dec[Full]);
					ukr += sprintf(ukr, "%s ", c[Ost]);
					ukr += sprintf(ukr, "��������i� ");
				}
				if (Ost == 0) {
					ukr += sprintf(ukr, "%s ", dec[Full]);
					ukr += sprintf(ukr, "��������i� ");
				}
				x %= 1000000000000;
			}
			if (h >= 1 && h <= 19) {
				if (h == 1) {
					ukr += sprintf(ukr, "���� ");
					ukr += sprintf(ukr, "�������� ");
					x %= 1000000000000;
				}
				if (h >= 2 && h <= 4) {
					ukr += sprintf(ukr, "%s ", dec[h]);
					ukr += sprintf(ukr, "%s ", c[h]);
					ukr += sprintf(ukr, "��������� ");
					x %= 1000000000000;
				}
				if (h >= 5 && h <= 19) {
					ukr += sprintf(ukr, "%s ", c[h]);
					ukr += sprintf(ukr, "��������i� ");
					x %= 1000000000000;
				}
			}
		}
	}
	if (x >= 1000000000) {
		long long int h = x;
		check = true;
		if ((h % 1000000000) == 0) {
			x /= 1000000000;
			if (x >= 100 && x <= 999) {
				int j = x;
				x /= 100;
				ukr += sprintf(ukr, "%s ", sog[x]);
				if ((j %= 100) == 0) {
					ukr += sprintf(ukr, "�i��������");
					j = 0;
					x = 0;
				}
				if (j >= 20 && j <= 99) {
					int Full = j / 10;
					int Ost = j % 10;
					ukr += sprintf(ukr, "%s ", thous[Full]);
					ukr += sprintf(ukr, "%s ", thou[Ost]);
					ukr += sprintf(ukr, "�i��������");
					j = 0;
					x = 0;
				}
				if (j >= 1 && j <= 19) {
					if (j == 1) {
						ukr += sprintf(ukr, "%s ", thou[j]);
						ukr += sprintf(ukr, "�i��������");
						return _strdup(arr);
					}
					else {
						ukr += sprintf(ukr, "%s ", thou[j]);
						ukr += sprintf(ukr, "�i��������");
					}
					j = 0;
					x = 0;
				}
			}
			if (x >= 20 && x <= 99) {
				int Full = x / 10;
				int Ost = x % 10;
				ukr += sprintf(ukr, "%s ", thous[Full]);
				ukr += sprintf(ukr, "%s ", thou[Ost]);
				ukr += sprintf(ukr, "�i��������");
				x = 0;
			}
			if (x >= 1 && x <= 19) {
				if (x == 1) {
					ukr += sprintf(ukr, "%s ", thou[x - 1]);
					ukr += sprintf(ukr, "�i��������");
					return _strdup(arr);
				}
				else {
					ukr += sprintf(ukr, "%s ", thou[x]);
					ukr += sprintf(ukr, "�i��������");
				}
				x = 0;
			}
		}
		else {
			h /= 1000000000;
			long long int q = h;
			if (q >= 100 && q <= 999) {
				q /= 100;
				ukr += sprintf(ukr, "%s ", sog[q]);
				h %= 100;
			}
			if (h >= 20 && h <= 99) {
				int Full = h / 10;
				int Ost = h % 10;
				if (Ost == 1) {
					ukr += sprintf(ukr, "%s ", dec[Full]);
					ukr += sprintf(ukr, "���� ");
					ukr += sprintf(ukr, "�i����� ");
				}
				if (Ost >= 2 && Ost <= 4) {
					ukr += sprintf(ukr, "%s ", dec[Full]);
					ukr += sprintf(ukr, "%s ", c[Ost]);
					ukr += sprintf(ukr, "�i������ ");
				}
				if (Ost >= 5 && Ost <= 99) {
					ukr += sprintf(ukr, "%s ", dec[Full]);
					ukr += sprintf(ukr, "%s ", c[Ost]);
					ukr += sprintf(ukr, "�i�����i� ");
				}
				if (Ost == 0) {
					ukr += sprintf(ukr, "%s ", dec[Full]);
					ukr += sprintf(ukr, "�i�����i� ");
				}
				x %= 1000000000;
			}
			if (h >= 1 && h <= 19) {
				if (h == 1) {
					ukr += sprintf(ukr, "���� ");
					ukr += sprintf(ukr, "�i����� ");
					x %= 1000000000;
				}
				if (h >= 2 && h <= 4) {
					ukr += sprintf(ukr, "%s ", dec[h]);
					ukr += sprintf(ukr, "%s ", c[h]);
					ukr += sprintf(ukr, "�i������ ");
					x %= 1000000000;
				}
				if (h >= 5 && h <= 19) {
					ukr += sprintf(ukr, "%s ", c[h]);
					ukr += sprintf(ukr, "�i�����i� ");
					x %= 1000000000;
				}
			}
		}
	}
	if (x >= 1000000) {
		int h = x;
		check = true;
		if ((h % 1000000) == 0) {
			x /= 1000000;
			if (x >= 100 && x <= 999) {
				int j = x;
				x /= 100;
				ukr += sprintf(ukr, "%s ", sog[x]);
				if ((j %= 100) == 0) {
					ukr += sprintf(ukr, "�i��������");
					j = 0;
					x = 0;
				}
				if (j >= 20 && j <= 99) {
					int Full = j / 10;
					int Ost = j % 10;
					ukr += sprintf(ukr, "%s ", thous[Full]);
					ukr += sprintf(ukr, "%s ", thou[Ost]);
					ukr += sprintf(ukr, "�i��������");
					j = 0;
					x = 0;
				}
				if (j >= 1 && j <= 19) {
					if (j == 1) {
						ukr += sprintf(ukr, "%s ", thou[j]);
						ukr += sprintf(ukr, "�i��������");
						return _strdup(arr);
					}
					else {
						ukr += sprintf(ukr, "%s ", thou[j]);
						ukr += sprintf(ukr, "�i��������");
					}
					j = 0;
					x = 0;
				}
			}
			if (x >= 20 && x <= 99) {
				int Full = x / 10;
				int Ost = x % 10;
				ukr += sprintf(ukr, "%s ", thous[Full]);
				ukr += sprintf(ukr, "%s ", thou[Ost]);
				ukr += sprintf(ukr, "�i��������");
				x = 0;
			}
			if (x >= 1 && x <= 19) {
				if (x == 1) {
					ukr += sprintf(ukr, "%s ", thou[x - 1]);
					ukr += sprintf(ukr, "�i��������");
					return _strdup(arr);
				}
				else {
					ukr += sprintf(ukr, "%s ", thou[x]);
					ukr += sprintf(ukr, "�i��������");
				}
				x = 0;
			}
		}
		else {
			h /= 1000000;
			int q = h;
			if (q >= 100 && q <= 999) {
				q /= 100;
				ukr += sprintf(ukr, "%s ", sog[q]);
				h %= 100;
			}
			if (h >= 20 && h <= 99) {
				int Full = h / 10;
				int Ost = h % 10;
				if (Ost == 1) {
					ukr += sprintf(ukr, "%s ", dec[Full]);
					ukr += sprintf(ukr, "���� ");
					ukr += sprintf(ukr, "�i����� ");
				}
				if (Ost >= 2 && Ost <= 4) {
					ukr += sprintf(ukr, "%s ", dec[Full]);
					ukr += sprintf(ukr, "%s ", c[Ost]);
					ukr += sprintf(ukr, "�i������ ");
				}
				if (Ost >= 5 && Ost <= 99) {
					ukr += sprintf(ukr, "%s ", dec[Full]);
					ukr += sprintf(ukr, "%s ", c[Ost]);
					ukr += sprintf(ukr, "�i�����i� ");
				}
				if (Ost == 0) {
					ukr += sprintf(ukr, "%s ", dec[Full]);
					ukr += sprintf(ukr, "�i�����i� ");
				}
				x %= 1000000; // ok
			}
			if (h >= 1 && h <= 19) {
				if (h == 1) {
					ukr += sprintf(ukr, "���� ");
					ukr += sprintf(ukr, "�i����� ");
					x %= 1000000;
				}
				if (h >= 2 && h <= 4) {
					ukr += sprintf(ukr, "%s ", dec[h]);
					ukr += sprintf(ukr, "%s ", c[h]);
					ukr += sprintf(ukr, "�i������ ");
					x %= 1000000;
				}
				if (h >= 5 && h <= 19) {
					ukr += sprintf(ukr, "%s ", c[h]);
					ukr += sprintf(ukr, "�i�����i� ");
					x %= 1000000;
				}
			}
		}
	}
	if (x >= 1000) {
		int h = x;
		check = true;
		if ((h % 1000) == 0) {
			x /= 1000;
			if (x >= 100 && x <= 999) {
				int j = x;
				x /= 100;
				ukr += sprintf(ukr, "%s ", sog[x]);
				if ((j %= 100) == 0) {
					ukr += sprintf(ukr, "��������");
					j = 0;
					x = 0;
				}
				if (j >= 20 && j <= 99) {
					int Full = j / 10;
					int Ost = j % 10;
					ukr += sprintf(ukr, "%s ", thous[Full]);
					ukr += sprintf(ukr, "%s ", thou[Ost]);
					ukr += sprintf(ukr, "��������");
					j = 0;
					x = 0;
				}
				if (j >= 1 && j <= 19) {
					if (j == 1) {
						ukr += sprintf(ukr, "%s ", thou[j]);
						ukr += sprintf(ukr, "��������");
						return _strdup(arr);
					}
					else {
						ukr += sprintf(ukr, "%s ", thou[j]);
						ukr += sprintf(ukr, "��������");
					}
					j = 0;
					x = 0;
				}
			}
			if (x >= 20 && x <= 99) {
				int Full = x / 10;
				int Ost = x % 10;
				ukr += sprintf(ukr, "%s ", thous[Full]);
				ukr += sprintf(ukr, "%s ", thou[Ost]);
				ukr += sprintf(ukr, "��������");
				x = 0;
			}
			if (x >= 1 && x <= 19) {
				if (x == 1) {
					ukr += sprintf(ukr, "%s ", thou[x - 1]);
					ukr += sprintf(ukr, "��������");
					return _strdup(arr);
				}
				else {
					ukr += sprintf(ukr, "%s ", thou[x]);
					ukr += sprintf(ukr, "��������");
				}
				x = 0;
			}
		}
		else {
			h /= 1000;
			int q = h;
			if (q >= 100 && q <= 999) {
				q /= 100;
				ukr += sprintf(ukr, "%s ", sog[q]);
				h %= 100;
			}
			if (h >= 20 && h <= 99) {
				int Full = h / 10;
				int Ost = h % 10;
				if (Ost == 1) {
					ukr += sprintf(ukr, "%s ", dec[Full]);
					ukr += sprintf(ukr, "���� ");
					ukr += sprintf(ukr, "������ ");
				}
				if (Ost >= 2 && Ost <= 4) {
					ukr += sprintf(ukr, "%s ", dec[Full]);
					Ost == 2 ? ukr += sprintf(ukr, "��i ") : ukr += sprintf(ukr, "%s ", c[Ost]);
					ukr += sprintf(ukr, "�����i ");
				}
				if (Ost >= 5 && Ost <= 99) {
					ukr += sprintf(ukr, "%s ", dec[Full]);
					ukr += sprintf(ukr, "%s ", c[Ost]);
					ukr += sprintf(ukr, "����� ");
				}
				if (Ost == 0) {
					ukr += sprintf(ukr, "%s ", dec[Full]);
					ukr += sprintf(ukr, "����� ");
				}
				x %= 1000;
			}
			if (h >= 1 && h <= 19) {
				if (h == 1) {
					ukr += sprintf(ukr, "���� ");
					ukr += sprintf(ukr, "������ ");
					x %= 1000;
				}
				if (h >= 2 && h <= 4) {
					h == 2 ? ukr += sprintf(ukr, "��i ") : ukr += sprintf(ukr, "%s ", c[h]);
					ukr += sprintf(ukr, "�����i ");
					x %= 1000;
				}
				if (h >= 5 && h <= 19) {
					ukr += sprintf(ukr, "%s ", c[h]);
					ukr += sprintf(ukr, "����� ");
					x %= 1000;
				}
			}
		}
	}
	if (x >= 100) {
		int n = x;
		if ((n % 100) == 0) {
			x /= 100;
			ukr += sprintf(ukr, "%s ", sot[x]);
		}
		else {
			ukr += sprintf(ukr, "%s ", sog[x / 100]);
			x %= 100;
			if (x <= 10) {
				ukr += sprintf(ukr, d[x]);
				return _strdup(arr);
			}
		}
		check = false;
	}
	if (x >= 20) {
		int z = x;
		if ((z %= 10) == 0) {
			x /= 10;
			ukr += sprintf(ukr, "%s ", des[x]);
		}
		else {
			x /= 10;
			ukr += sprintf(ukr, "%s ", dec[x]);
			z %= 10;
			ukr += sprintf(ukr, "%s ", d[z]);
		}
	}
	if (x >= 11) {
		x %= 10;
		switch (x) {
		case 1: ukr += sprintf(ukr, "���"); break;
		case 4: ukr += sprintf(ukr, "�����"); break;
		case 5: ukr += sprintf(ukr, "�'��"); break;
		case 6: ukr += sprintf(ukr, "�i��"); break;
		case 9: ukr += sprintf(ukr, "���'��"); break;
		default: ukr += sprintf(ukr, c[x]);
		}
		ukr += sprintf(ukr, "��������");
	}
	else if (x > 0)
		if (check == true)
		{
			ukr += sprintf(ukr, "%s ", d[x]);
			return _strdup(arr);
		}
	return _strdup(arr);
}
};
