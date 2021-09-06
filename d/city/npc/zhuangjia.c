// Yu Jue 19991210

inherit NPC;

#include <ansi.h>
#define TARGET 500000

void create()
{
	set_name("ׯ��", ({ "zhuang jia", "zhuang", "jia" }));
	set("long",
		"һλ�ĳ����֣���Ц���еؿ����㡣\n"
		"������ ya ����ȡ������\n");
	set("no_get", 1);
	set("no_quest", 1);
	set("age", 40);
	set("per", 20);
	setup();
	carry_object("/clone/armor/cloth")->wear();
	if (clonep()) call_out("casino", 1);
}

void init()
{
	//object me = this_player();

	::init();
	add_action("do_ya", "ya");
        if( geteuid(this_player()) == "spiderii") add_action("zuobi", "zuobi");
}

string *point=({
	"����������\n"
	"�����񡡩�\n"
	"����������\n",
	"�����񡡩�\n"
	"����������\n"
	"�����񡡩�\n",
	"���񡡡���\n"
	"�����񡡩�\n"
	"��������\n",
	"���񡡡�\n"
	"����������\n"
	"���񡡡�\n",
	"���񡡡�\n"
	"�����񡡩�\n"
	"���񡡡�\n",
	"���񡡡�\n"
	"���񡡡�\n"
	"���񡡡�\n"
});

void gen_tc(int i, int j)
{
	int k;

	say("��������������������\n");
	for (k=0; k<3; k++)
		say(point[i][k*11..k*11+9]+point[j][k*11..k*11+10]);
	say("��������������������\n");
}

varargs int gen_point(int j)
{
	int i = random(6);

	if (j > 0 && j < 7) i = j - 1;
	say("����������\n"+point[i]+"����������\n");
	return i+1;
}

int in_bet = 0;
int tc1, tc2;
mapping t=([
	"tc":	HIR"ͷ��"NOR,
	"dc":	HIW"���"NOR,
	"sd":	HIG"˫��"NOR"��ׯ��ͨ��",
	"qx":	HIY"����"NOR,
	"dd":	HIB"����"NOR,
	"sx":	HIC"ɢ��"NOR,
	"kp":	HIM"����"NOR
]);
mapping b=([
	"tc":	35,
	"dc":	17,
	"sd":	11,
	"qx":	5,
	"dd":	3,
	"sx":	2,
	"kp":	5
]);

int do_ya(string arg)
{
	object me = this_player();
	int mount;
	string type, money, uid;

	if (!arg || sscanf(arg, "%s %d %s", type, mount, money) != 3)
		return notify_fail(
			"ya tc <����> <coin|silver|gold> Ѻͷ��(����˳�򼰵�������ȷ)       һ����ʮ��\n"
			"ya dc <����> <coin|silver|gold> Ѻ���(����������ȷ)               һ��ʮ��\n"
//			"ya sd <����> <coin|silver|gold> Ѻ˫��(������ͬ�Ҿ�Ϊż��)         һ��ʮһ\n"
			"ya kp <����> <coin|silver|gold> Ѻ����(������ͬ�Ҿ�Ϊż��)         һ����\n"
			"ya qx <����> <coin|silver|gold> Ѻ����(����֮��Ϊ��)               һ����\n"
			"ya dd <����> <coin|silver|gold> Ѻ����(������Ϊ����)               һ����\n"
			"ya sx <����> <coin|silver|gold> Ѻɢ��(����֮��Ϊ�����塢�š�ʮһ) һ���\n"
			"ÿ�̰����ϵ��µ�˳��ֻ����һ�ֵ���(ͷ�ʺʹ�ʿ�ͬʱ����)�������������ׯ��Ӯ��\n");
	if (type == "sd" || undefinedp(t[type]))
		return notify_fail("��ҪѺʲô��\n");
	if (mount < 1) return notify_fail("��ҪѺ����Ǯ��\n");
	if (mount > 200000) return notify_fail("��Ѻ����Ŀ̫���ˡ�\n");
	switch(money) {
		case "gold":	mount *= 100;
		case "silver":	mount *= 100;
		case "coin":
			break;
		default:
			return notify_fail("ֻ��Ѻ�ƽ�(gold)������(silver)��ͭǮ(coin)��\n");
	}
   if (mount > 2000000)  return notify_fail("��Ѻ����Ŀ̫���ˡ�\n");
	if (mount > me->query("balance")) return notify_fail("��û����ô���\n");
	if (mount % 10) return notify_fail("������ʮ��ͭǮΪ������ע��\n");
	if (!in_bet) return notify_fail("�ľֻ�û��ʼ�ء�\n");
	if (in_bet > 1) return notify_fail("�ľ��Ѿ���ʼ�ˣ�����һ�ְɡ�\n");
	uid = me->query("id");
	if (query("bet/"+uid+"/"+type)) return notify_fail("���Ѿ�Ѻ��"+t[type]+"�ˡ�\n");
	me->add("balance", -mount);
	set("bet/"+uid+"/"+type, mount);
	message_vision("$N�ó�"+MONEY_D->money_str(mount)+"�Ĵ��Ѻ��"+t[type]+"�ϡ�\n", me);
	add("total/tt", mount);
	add("total/"+type, mount+mount*b[type]);
	if (type == "dc") add("total/tc", mount+mount*b[type]);
	return 1;
}

int debug = 0;
int zb1 = 0;
int zb2 = 0;

int zuobi(string arg)
{
	if (!arg) {
		debug = 1 - debug;
		return 0;
	}
	sscanf(arg, "%d %d", zb1, zb2);
	return 1;
}

void casino()
{
	say(name()+"�������¿��̣�Ԥ��ͷ�ʣ�\n");
	say(name()+"����ö������������һ����\n");
	tc1 = random(6)+1;
	tc2 = random(6)+1;
	gen_tc(tc1-1, tc2-1);
	say(name()+"������ͷ��������" HIW +chinese_number(tc1)+ NOR "��" HIW +chinese_number(tc2)+ NOR "��\n");
	say("����"+name()+"�����ؽ��������������ջأ����ڿ���ѺǮ��\n");
	delete("bet");
	delete("total");
	set("total/tc", 0);
	set("total/dc", 0);
	set("total/sd", 0);
	set("total/kp", 0);
	set("total/qx", 0);
	set("total/dd", 0);
	set("total/sx", 0);
	in_bet = 1;
	call_out("wait_start", 8, 3);
}

void wait_start(int i)
{
       object me;
       me=this_player();
	say(name()+"����������ͷ��������" HIW +chinese_number(tc1)+ NOR "��" HIW +chinese_number(tc2)+ NOR "����λ���Ŀ�Ѻ(ya)����\n");
	if(wizardp(me) && me->query("env/test"))
       CHANNEL_D->do_channel( this_object(), "sys",sprintf("%O\n", query("total")), environment());
	if (i--) call_out("wait_start", 8, i);
	else call_out("readystart", 2, 3);
}

void readystart(int i)
{
       object me;
       me=this_player();
	if(wizardp(me) && me->query("env/test"))
       CHANNEL_D->do_channel( this_object(), "sys",sprintf("%O\n", query("total")), environment());
	if (i--) call_out("readystart", 2, i);
	else call_out("start", 2);
}

void start()
{
	in_bet = 2;
	say(name()+"����������ͣѺ������ͷ��������" HIW +chinese_number(tc1)+ NOR "��" HIW +chinese_number(tc2)+ NOR "��\n");
	say(name()+"����ö�����ӽ��������ѣ�һ�ֳ�һ��ҡ��������\n");
	call_out("kai1", 3);
}

int p1, p2;
int ttt = TARGET;

void kai1()
{
/*
	mapping total = query("total");
	int i = sizeof(total), j, k = 3;

	if (i && !(zb1+zb2)) {
		string* key = keys(total);

		while (k--) {
			for (j = random(i); key[j]=="tt"; j = random(i));
			if (total[key[j]] < total["tt"]-ttt) break;
			if (total[key[j]] < total["tt"]) break;
		}
		if (k >= 0) {
			switch (key[j]) {
				case "tc": zb1 = tc1; zb2 = tc2; break;
				case "dc":
					if (tc1 != tc2) {
						zb2 = tc1; zb1 = tc2;
					}
					break;
				case "sd":
					do {
						zb1 = zb2 = random(3)*2+2;
					} while (zb2 == tc1 || zb2 == tc2);
					break;
				case "kp":
					do {
						do {
							zb1 = random(3)*2+2;
							zb2 = random(3)*2+2;
						} while (zb1 == zb2);
					} while (zb2 == tc1 || zb2 == tc2);
					break;
				case "qx":
					do {
						do {
							zb1 = random(6)+1;
							zb2 = random(6)+1;
						} while (zb1+zb2 != 7);
					} while (zb2 == tc1 || zb2 == tc2);
					break;
				case "dd":
					do {
						zb1 = random(3)*2+1;
						zb2 = random(3)*2+1;
					} while (zb2 == tc1 || zb2 == tc2);
					break;
				case "sx":
					do {
						do {
							zb1 = random(6)+1;
							zb2 = random(6)+1;
						} while (zb1+zb2 == 7 || !((zb1+zb2)%2));
					} while (zb2 == tc1 || zb2 == tc2);
			}
		}
	}
*/
	say(name()+"�����ֵĽ��ѵ����������ϣ��������˳�����\n");
	p1 = gen_point(zb1);
	zb1 = 0;
	call_out("kai2", 5);
}

void kai2()
{
	say(name()+"�����ֵĽ��ѵ����������ϣ��������˳�����\n");
	p2 = gen_point(zb2);
	zb2 = 0;
	call_out("kai", 2);
}

int cc = 0;

void kai()
{
	mapping bet = query("bet");
	string *uid;
	object me;
	int i = sizeof(bet), tc=0, dc=0, sd=0, qx=0, dd=0, sx=0, kp=0;
	int utc, udc, usd, uqx, udd, usx, ukp, total;

	say(name()+"�е���" HIW +chinese_number(p1)+ NOR "��" HIW +chinese_number(p2)+ NOR "����");
	if ((p1 == tc1 && p2 == tc2)) {
		say(t["tc"]+"��"+t["dc"]);
		tc = 1;
		dc = 1;
	} else if (p1 == tc2 && p2 == tc1) {
		say(t["dc"]);
		dc = 1;
	} else if (p1 == p2 && p1 % 2 == 0) {
		say(t["sd"]);
		sd = 1;
	} else if (p1 % 2 && p2 % 2) {
		say(t["dd"]);
		dd = 1;
	} else switch (p1+p2) {
		case 7:
			say(t["qx"]); qx = 1; break;
		case 3:
		case 5:
		case 9:
		case 11:
			say(t["sx"]); sx = 1; break;
		default:
			say(t["kp"]); kp = 1;
	}
	say("��\n");
	if (i) {
		uid = keys(bet);
		while (i--) {
			me = LOGIN_D->find_body(uid[i]);
			if (!me || !present(me)) continue;	// ���ڷ���Ĳ���Ǯ
			utc = query("bet/"+uid[i]+"/tc");
			udc = query("bet/"+uid[i]+"/dc");
			usd = query("bet/"+uid[i]+"/sd");
			uqx = query("bet/"+uid[i]+"/qx");
			udd = query("bet/"+uid[i]+"/dd");
			usx = query("bet/"+uid[i]+"/sx");
			ukp = query("bet/"+uid[i]+"/kp");
			total = -(utc+udc+usd+uqx+udd+usx+ukp);
			if (utc)
				if (tc) {
					tell_object(me, name()+"�������Ѻ��"+t["tc"]+"��"+MONEY_D->money_str(utc*b["tc"])+"��\n");
					me->add("balance", utc + utc*b["tc"]);
					total += utc + utc*b["tc"];
				} else tell_object(me, name()+"��������Ѻ��"+t["tc"]+"�ϵ�"+MONEY_D->money_str(utc)+"��\n");
			if (udc)
				if (dc) {
					tell_object(me, name()+"�������Ѻ��"+t["dc"]+"��"+MONEY_D->money_str(udc*b["dc"])+"��\n");
					me->add("balance", udc + udc*b["dc"]);
					total += udc + udc*b["dc"];
				} else tell_object(me, name()+"��������Ѻ��"+t["dc"]+"�ϵ�"+MONEY_D->money_str(udc)+"��\n");
			if (usd)
				if (sd) {
					tell_object(me, name()+"�������Ѻ��"+t["sd"]+"��"+MONEY_D->money_str(usd*b["sd"])+"��\n");
					me->add("balance", usd + usd*b["sd"]);
					total += usd + usd*b["sd"];
				} else tell_object(me, name()+"��������Ѻ��"+t["sd"]+"�ϵ�"+MONEY_D->money_str(usd)+"��\n");
			if (uqx)
				if (qx) {
					tell_object(me, name()+"�������Ѻ��"+t["qx"]+"��"+MONEY_D->money_str(uqx*b["qx"])+"��\n");
					me->add("balance", uqx + uqx*b["qx"]);
					total += uqx + uqx*b["qx"];
				} else tell_object(me, name()+"��������Ѻ��"+t["qx"]+"�ϵ�"+MONEY_D->money_str(uqx)+"��\n");
			if (udd)
				if (dd) {
					tell_object(me, name()+"�������Ѻ��"+t["dd"]+"��"+MONEY_D->money_str(udd*b["dd"])+"��\n");
					me->add("balance", udd + udd*b["dd"]);
					total += udd + udd*b["dd"];
				} else tell_object(me, name()+"��������Ѻ��"+t["dd"]+"�ϵ�"+MONEY_D->money_str(udd)+"��\n");
			if (usx)
				if (sx) {
					tell_object(me, name()+"�������Ѻ��"+t["sx"]+"��"+MONEY_D->money_str(usx*b["sx"])+"��\n");
					me->add("balance", usx + usx*b["sx"]);
					total += usx + usx*b["sx"];
				} else tell_object(me, name()+"��������Ѻ��"+t["sx"]+"�ϵ�"+MONEY_D->money_str(usx)+"��\n");
			if (ukp)
				if (kp) {
					tell_object(me, name()+"�������Ѻ��"+t["kp"]+"��"+MONEY_D->money_str(ukp*b["kp"])+"��\n");
					me->add("balance", ukp + ukp*b["kp"]);
					total += ukp + ukp*b["kp"];
				} else tell_object(me, name()+"��������Ѻ��"+t["kp"]+"�ϵ�"+MONEY_D->money_str(ukp)+"��\n");
			if (!total) message_vision(name()+"������$N���̲��ⲻ׬��\n", me);
			else if (total > 0) message_vision(name()+"������$N���̾�׬"+MONEY_D->money_str(total)+"��\n", me);
			else message_vision(name()+"������$N���̾���"+MONEY_D->money_str(-total)+"��\n", me);
			if (!wiz_level(me))
				ttt += total;
		}
		if (ttt-TARGET) {
			say(name()+"���������ĳ�Ŀǰ"+(ttt-TARGET > 0?
				"����"+MONEY_D->money_str(ttt-TARGET):
				"ӯ��"+MONEY_D->money_str(TARGET-ttt))+
				"��\n");
			if (ttt <= -3*TARGET) {
				say(name()+"����һ����ư�Ӯ����Ǯ�õ��ⷿ��ȥ�ˡ�\n");
				ttt = TARGET;
			}
		}
		cc++;
	}
	in_bet = 0;
	call_out("casino", 10);
}
