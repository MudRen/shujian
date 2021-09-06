// chinesed.c

#include <ansi.h>
#include <localtime.h>

#ifndef DATA_DIR
#define DATA_DIR 	"/data/"
#endif
#define E2C_DICTIONARY	DATA_DIR + "e2c_dict"
#define HZK16		"/data/HZK16.font"

inherit F_SAVE;

// some constatns
static string *c_digit = ({ "��","ʮ","��","ǧ","��","��" });
static string *c_num = ({"��","һ","��","��","��","��","��","��","��","��","ʮ"});
static string *sym_tian = ({ "��","��","��","��","��","��","��","��","��","��" });
static string *sym_di = ({ "��","��","��","î","��","��","��","δ","��","��","��","��" });

mapping dict = ([]);

void add_translate(string key, string chn);
void remove_translate(string key);

void create()
{
	seteuid(getuid());
	restore();
}

string chinese_number(int i)
{
	if (i < 0)
		return "��" + chinese_number(-i);
	if (i < 11)
		return c_num[i];
	if (i < 20)
		return c_digit[1] + c_num[i - 10];
	if (i < 100) {
		if (i % 10)
			return c_num[i / 10] + c_digit[1] + c_num[i % 10];
		else
			return c_num[i / 10] + c_digit[1];
	}
	if (i < 1000) {
		if (i % 100 == 0)
			return c_num[i / 100] + c_digit[2];
		else if (i % 100 < 10)
			return c_num[i / 100] + c_digit[2] +
			c_num[0] + c_num[i % 100];
		else if (i % 100 < 20)
			return c_num[i / 100] + c_digit[2] +
			c_num[1] + chinese_number(i % 100);
		else
			return c_num[i / 100] + c_digit[2] +
			chinese_number(i % 100);
	}
	if (i < 10000) {
		if (i % 1000 == 0)
			return c_num[i / 1000] + c_digit[3];
		else if (i % 1000 < 100)
			return c_num[i / 1000] + c_digit[3] +
			c_num[0] + chinese_number(i % 1000);
		else
			return c_num[i / 1000] + c_digit[3] +
			chinese_number(i % 1000);
	}
	if (i < 100000000) {
		if (i % 10000 == 0)
			return chinese_number(i / 10000) + c_digit[4];
		else if (i % 10000 < 1000)
			return chinese_number(i / 10000) + c_digit[4] +
			c_num[0] + chinese_number(i % 10000);
		else
			return chinese_number(i / 10000) + c_digit[4] +
			chinese_number(i % 10000);
	}
	if (i % 100000000 == 0)
		return chinese_number(i / 100000000) + c_digit[5];
	else if (i % 100000000 < 1000000)
		return chinese_number(i / 100000000) + c_digit[5] +
		c_num[0] + chinese_number(i % 100000000);
	else
		return chinese_number(i / 100000000) + c_digit[5] +
		chinese_number(i % 100000000);
}

string query_save_file()
{
	return E2C_DICTIONARY;
}

string chinese(string str)
{
	if (!undefinedp(dict[str]))
		return dict[str];
	else
		return str;
}

void remove_translate(string key)
{
	map_delete(dict, key);
	save();
}

void add_translate(string key, string chn)
{
	dict[key] = chn;
	save();
}

void dump_translate()
{
	string *k, str;
	int i;

	str = "";
	k = sort_array(keys(dict), 1);
	for (i = 0; i < sizeof(k); i++)
		str += sprintf("(%30s) (%30s) %6d\n", k[i], dict[k[i]], file_size(SKILL_D(k[i])+".c"));
	write_file("/CHINESE_DUMP", str);
}

string chinese_date(int date, int ad)
{
	mixed *local;
	int i, y, mo, d, h, m, s;
	string time;

	local = localtime(date);
	if (!ad) {
		i = (local[LT_HOUR]+1) % 2 * 2 + local[LT_MIN] / 30;
		return sprintf("%s%s��%s��%s��%sʱ%s",
			sym_tian[local[LT_YEAR] % 10], sym_di[local[LT_YEAR] % 12],
			chinese_number(local[LT_MON] + 1),
			chinese_number(local[LT_MDAY]),
			sym_di[((local[LT_HOUR] + 1) % 24) / 2],
			i?chinese_number(i) + "��":"��");
	}
	s = local[LT_SEC];
	m = local[LT_MIN];
	h = local[LT_HOUR];
	d = local[LT_MDAY];
	mo = local[LT_MON]+1;
	y = local[LT_YEAR];
	i = local[LT_YEAR];
	time = "��";

	while (y) {
		time = chinese_number(y%10) + time;
		y /= 10;
	}
	time += chinese_number(mo) + "��";
	time += chinese_number(d) + "��";
	time += chinese_number(h) + "ʱ";
	time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";
	return time;
}

string chinese_time(int total)
{
	int d, h, m, s;
	string tmp = "";

	if (!total)
		return "����";
	d = total / 86400;
	if (d) tmp += chinese_number(d) + "��";
	h = (total % 86400) / 3600;
	if (h) tmp += chinese_number(h) + "Сʱ";
	m = (total % 3600) / 60;
	if (m) tmp += chinese_number(m) + "��";
	s = total % 60;
	if (s) tmp += chinese_number(s) + "��";
	return tmp;
}

varargs string chinese_graph_font(string str,int show_mode)
{
	int i,j,k,a,len;
	string sout,show_char;
	int qh,wh,offset;
	buffer buf,buf2;

	if( str ) str = strip(str);
	if( !str || (len=strlen(str))<2 || (len%2)==1 )
		return "����������ַ�����";

	/*
	sout = "";
	for(i=1;i<255;i++)
		sout += sprintf("%d:%c\n",i,i);
	return sout;
	*/

	show_char = " ";
	show_char[0] = '*';
	if( show_mode==2 ) show_char[0] = 31;
	//if( show_mode ) show_char[0] = 31; else show_char[0] = '*';

	buf  = allocate_buffer(32);
	buf2 = allocate_buffer(256);
	len /= 2;
	k = len * 17 - 1;
	sout = repeat_string(repeat_string(" ", k) + "\n", 16);

	a = k + 1;
	for (i=0;i<len;i++) {
		qh = str[i*2]   - 0xA0;
		wh = str[i*2+1] - 0xA0;
		offset = (94*(qh-1)+(wh-1))*32;

		buf = read_buffer(HZK16,offset,32);
		for(j=0;j<32;j++) {
			buf2[j*8+0] = buf[j] & 0x80;
			buf2[j*8+1] = buf[j] & 0x40;
			buf2[j*8+2] = buf[j] & 0x20;
			buf2[j*8+3] = buf[j] & 0x10;
			buf2[j*8+4] = buf[j] & 0x08;
			buf2[j*8+5] = buf[j] & 0x04;
			buf2[j*8+6] = buf[j] & 0x02;
			buf2[j*8+7] = buf[j] & 0x01;
		}

		for(j=0;j<16;j++) {
			for(k=0;k<16;k++) {
				if (buf2[j*16+k])
					sout[j*a+i*17+k] = show_char[0];
			}
		}
	}

	return sout;
}

string font(string str)
{
	int i,j,k,a,len;
	string sout;
	int qh,wh,offset;
	buffer buf,buf2;
	
	if(this_player() && this_player()->query("env/show_mode"))
		return chinese_graph_font(str,(int)this_player()->query("env/show_mode") );

	if (str) str = strip(str);
	if (!str || (len=strlen(str))<2 || (len%2)==1)
		return "����������ַ�����\n";

	buf  = allocate_buffer(32);
	buf2 = allocate_buffer(256);
	len /= 2;
	k = len * 17 - 1;
	sout = repeat_string(repeat_string(" ", k) + "\n", 8);

	a = k + 1;
	for (i=0;i<len;i++) {
		qh = str[i*2]   - 0xA0;
		wh = str[i*2+1] - 0xA0;
		offset = (94*(qh-1)+(wh-1))*32;

		buf = read_buffer(HZK16,offset,32);
		for(j=0;j<32;j++) {
			buf2[j*8+0] = buf[j] & 0x80;
			buf2[j*8+1] = buf[j] & 0x40;
			buf2[j*8+2] = buf[j] & 0x20;
			buf2[j*8+3] = buf[j] & 0x10;
			buf2[j*8+4] = buf[j] & 0x08;
			buf2[j*8+5] = buf[j] & 0x04;
			buf2[j*8+6] = buf[j] & 0x02;
			buf2[j*8+7] = buf[j] & 0x01;
		}

		for(j=0;j<8;j++) {
			for(k=0;k<16;k++) {
				if (buf2[j*32+k]) {
					if (buf2[j*32+k+16])
						sout[j*a+i*17+k] = ':';
					else
						sout[j*a+i*17+k] = '`';
				} else {
					if (buf2[j*32+k+16])
						sout[j*a+i*17+k] = '.';
				}
			}
		}
	}

	return sout;
}

string get_title(string arg1, string arg2)
{
	string arg;
	arg = YEL"
	�X�����������������������������[\n"+
sprintf("	��"HIY"%|28s"YEL"��\n	��    "HIR"%|24s"YEL"��\n",arg1,arg2?arg2:"��")+
"	�^�����������������������������a\n\n"NOR;
	return arg;
}
