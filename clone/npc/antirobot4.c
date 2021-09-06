// designed by Yu Jue
// Modified by snowman@SJ 12/06/2000
// Powered by Yu Jue 2000-08/09
// Powered again by YUJ@SJ 2001-05-06

#define HW "[0;37;40m"
#define BK "[30;40m"

#define FONTLIB 3

#include <ansi.h>

inherit NPC;

mixed keypos=({
	({ 0,0,0,0,0,0,0,0,0,0 }),
	({ 0,0,0,0,0,0,0,0,0,0 }),
	({ 0,0,0,0,0,0,0,0,0,0 })
});

mixed keylen=({
	({  8, 4, 8, 8, 8, 8, 8, 8, 8, 8 }),
	({  8, 4, 8, 8, 8, 8, 8, 8, 8, 8 }),
	({ 10, 4,10,10,10,10,10,10,10,10 })
});

mixed key=({
	({
		"¡ö¡ö¡ö¡¡¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡¡¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡",
		"¡ö¡¡¡ö¡¡¡ö¡¡¡¡¡¡¡ö¡¡¡¡¡¡¡ö¡¡¡ö¡¡¡ö¡¡¡ö¡¡¡¡¡¡¡ö¡¡¡¡¡¡¡¡¡¡¡ö¡¡¡ö¡¡¡ö¡¡¡ö¡¡¡ö¡¡",
		"¡ö¡¡¡ö¡¡¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡¡¡¡¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡",
		"¡ö¡¡¡ö¡¡¡ö¡¡¡ö¡¡¡¡¡¡¡¡¡¡¡ö¡¡¡¡¡¡¡ö¡¡¡¡¡¡¡ö¡¡¡ö¡¡¡ö¡¡¡¡¡¡¡ö¡¡¡ö¡¡¡ö¡¡¡¡¡¡¡ö¡¡",
		"¡ö¡ö¡ö¡¡¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡¡¡¡¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡¡¡¡¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡",
		"¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"
	}),
	({
		"¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡",
		"¡ö¡ö¡ö¡¡¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡¡¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡",
		"¡ö¡¡¡ö¡¡¡ö¡¡¡¡¡¡¡ö¡¡¡¡¡¡¡ö¡¡¡ö¡¡¡ö¡¡¡ö¡¡¡¡¡¡¡ö¡¡¡¡¡¡¡¡¡¡¡ö¡¡¡ö¡¡¡ö¡¡¡ö¡¡¡ö¡¡",
		"¡ö¡¡¡ö¡¡¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡¡¡¡¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡",
		"¡ö¡¡¡ö¡¡¡ö¡¡¡ö¡¡¡¡¡¡¡¡¡¡¡ö¡¡¡¡¡¡¡ö¡¡¡¡¡¡¡ö¡¡¡ö¡¡¡ö¡¡¡¡¡¡¡ö¡¡¡ö¡¡¡ö¡¡¡¡¡¡¡ö¡¡",
		"¡ö¡ö¡ö¡¡¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡¡¡¡¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡¡¡¡¡¡ö¡¡¡ö¡ö¡ö¡¡¡ö¡ö¡ö¡¡"
	}),
	({
		"©°©¤©¤©¤©´©°©´©°©¤©¤©¤©´©°©¤©¤©¤©´©°©´¡¡©°©´©°©¤©¤©¤©´©°©¤©¤©¤©´©°©¤©¤©¤©´©°©¤©¤©¤©´©°©¤©¤©¤©´",
		"©¦©°©¤©´©¦©¦©¦©¸©¤©¤©´©¦©¸©¤©¤©´©¦©¦©¦¡¡©¦©¦©¦©°©¤©¤©¼©¦©°©¤©¤©¼©¸©¤©¤©´©¦©¦©°©¤©´©¦©¦©°©¤©´©¦",
		"©¦©¦¡¡©¦©¦©¦©¦©°©¤©¤©¼©¦©°©¤©¤©¼©¦©¦©¸©¤©¼©¦©¦©¸©¤©¤©´©¦©¸©¤©¤©´¡¡¡¡¡¡©¦©¦©¦©¸©¤©¼©¦©¦©¸©¤©¼©¦",
		"©¦©¦¡¡©¦©¦©¦©¦©¦©°©¤©¤©¼©¸©¤©¤©´©¦©¸©¤©¤©´©¦©¸©¤©¤©´©¦©¦©°©¤©´©¦¡¡¡¡¡¡©¦©¦©¦©°©¤©´©¦©¸©¤©¤©´©¦",
		"©¦©¸©¤©¼©¦©¦©¦©¦©¸©¤©¤©´©°©¤©¤©¼©¦¡¡¡¡¡¡©¦©¦©°©¤©¤©¼©¦©¦©¸©¤©¼©¦¡¡¡¡¡¡©¦©¦©¦©¸©¤©¼©¦©°©¤©¤©¼©¦",
		"©¸©¤©¤©¤©¼©¸©¼©¸©¤©¤©¤©¼©¸©¤©¤©¤©¼¡¡¡¡¡¡©¸©¼©¸©¤©¤©¤©¼©¸©¤©¤©¤©¼¡¡¡¡¡¡©¸©¼©¸©¤©¤©¤©¼©¸©¤©¤©¤©¼"
	})
});

string ans="", ans1, fakeans="";
string str = "\nÒøÒíÉ±ÊÖËµµÀ£ºÇëÓÃ answer »Ø´ð£¬ÏÂÃæÕâÐÐÊý×ÖÊÇ£¿\n";
int aflag;
int num = 2;

#include "antirobot.h";

void question()
{
	message("channel", HW+str+NOR, ob);
	aflag = 1;
}

int do_answer(string arg)
{
	object me = this_object();
	int len = strlen(ans);

	if (arg) {
		int i = strlen(arg);

		while (i--)
			if (arg[i] == ' ')
				arg = arg[0..i-1] + arg[i+1..<1];
	} else
		arg = "";
	if (strlen(arg) != len)
		return notify_fail("´ð°¸µÄ³¤¶È²»¶Ô£¬ÔÙ×ÐÏ¸¿´¿´¡£\n");
	if (aflag) {
		aflag = 0;
		if (ans1 == arg) {
			command("wiz "+ob->query("id")+" ¼«¿ÉÄÜÊ¹ÓÃÁË×Ô¶¯Ó¦´ð»úÆ÷ÈË£¬Çë¼ì²é£¡");
			return notify_fail("´ð°¸²»¶Ô£¬Èç¹û¿´²»Çå³þ£¬Çë½«×ÖÌåÉèÖÃÎª Fixedsys¡£\n");
		}
		ans1 = arg;
	}
	if (arg==ans) {
		message_vision("$NµãÁËµãÍ·£¬ËµµÀ£ºOK£¬$n¼ÌÐøÃ¦°É¡£\n", me, ob);
		if (num == 2) give_reward(ob);
		message_vision("$NÍ»È»ÏûÊ§²»¼ûÁË¡£\n", me);
	} else {
		if (arg==fakeans)
			command("wiz "+ob->query("id")+" ¾ø¶ÔÊ¹ÓÃÁË×Ô¶¯Ó¦´ð»úÆ÷ÈË£¬Çë´þ²¶£¡");
		if (num--)
			return notify_fail("´ð°¸²»¶Ô£¬Èç¹û¿´²»Çå³þ£¬Çë½«×ÖÌåÉèÖÃÎª Fixedsys¡£\n");
		message_vision("$NÌ¾ÁË¿ÚÆøµÀ£º"+arg+"£¿"+ans+"²Å¶Ô£¬ÕâÃ´¼òµ¥¶¼´ð²»³ö£¿È¥·¨Í¥½ÓÊÜñöÑ¶°É£¡\n", me);
		move_to_court(ob);
	}
	destruct(this_object());
	return 1;
}

void test_robot(object obj)
{
	int len, temp, c, l, font, pos, end;
	string *line=({"", "", "", "", "", ""}), ta;
	string *line1=({"", "", "", "", "", ""}), gap;
	object me = this_object();

	ob = obj;
	if (environment(ob) && !ob->is_fighting()) {
		message("channel", "ÒøÒíÉ±ÊÖÂÔ´øÇ¸ÒâµØËµ£º¡°»úÆ÷ÈË»ü²é£¬ÀýÐÐ¹«ÊÂ£¬Çë»Ø´ðÒ»¸öÐ¡ÎÊÌâ¡£¡±\n", ob);
		message("channel", "Èç¹ûÀûÓÃ»úÆ÷×Ô¶¯»Ø´ðÎÊÌâ£¬µµ°¸½«±»ÎÞÌõ¼þÉ¾³ý¡£\n", ob);
		for (l = 0; l < FONTLIB; l++)
			for (temp = 1; temp < 10; temp++)
				keypos[l][temp] = keypos[l][temp-1] + keylen[l][temp-1];

		// Éú³É´ð°¸
		temp = len = random(2) + 2;
		while (temp--) {
			ans += "0";
			ans[<1] += random(10);
			fakeans += "0";
			fakeans[<1] += ans[<1] == '1'?1:2+random(8);
		}

		for (temp = 0; temp < len; temp++) {
			gap = repeat_string("¡¡", 1+random(2));
			c = ans[temp] - '0';
			font = random(FONTLIB);
			pos = keypos[font][c];
			end = pos + keylen[font][c] -1;
			for (l = 0; l < 6; l++)
				line[l] += gap + key[font][l][pos..end];
			c = fakeans[temp] - '0';
			pos = keypos[font][c];
			end = pos + keylen[font][c] -1;
			for (l = 0; l < 6; l++)
				line1[l] += gap + key[font][l][pos..end];
		}
		str += repeat_string("ºÙºÙ\n", 6);
		gap = repeat_string("¡¡", 1+random(2));
		for (l = 0; l < 6;) {
			temp = random(6);
			if (!line[temp]) continue;
			str += "["+(6-temp)+"A";
			str += line[temp] + gap;
			str += repeat_string("\n", 6-temp);
			line[temp] = 0;
			l++;
		}
		// ¸ÉÈÅ×Ö·û
		for (l = 50; l < strlen(str); l++) {
			if (str[l] < 161) continue;
			if (str[l..l+1] == "¡¡") {
				if (!random(3)) {
					string *tab = key[random(FONTLIB)];

					ta = tab[random(sizeof(tab))];
					c = random(sizeof(ta)/2)*2;
					str = str[0..l-1]
						+ BK + ta[c..c+1]
						+ HW + str[l+2..<1];
					l += strlen(BK+HW);
				}
			}
			l++;
		}
		timer = 180;
		call_out("test1", 10);
		me->move(ob, 1);
	} else destruct(me);
}
