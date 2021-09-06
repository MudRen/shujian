// Room: /d/huashan/shulin.c
// Date: Look 99/03/25

inherit ROOM;

#include <ansi.h>
int check(object ob);
string get_place(string str);

string* msg1 = ({"��Ȼ","ͻȻ",	"�͵�",	"�䲻��",});
string* msg2 = ({"��������","�������",});
string* msg3 = ({"�ܳ�","ɱ��",});
string* msg4 = ({"һ�Ѷ���","����","һ����ȥ","��ȥ",});
string* msg5 = ({"��",	"����",	"����·","�����·",});

string* names = ({
"/d/village/caidi",	"/d/village/shilu1",	"/d/village/shilu2",
"/d/village/shilu3",	"/d/village/shilu4",	"/d/village/shilu5",
"/d/village/shilu6",	__DIR__"canglong",	__DIR__"celang1",
__DIR__"celang2",	__DIR__"chaoyang",	__DIR__"husun",
__DIR__"pubu",		__DIR__"qianchi",	__DIR__"qingke",
__DIR__"shaluo",	__DIR__"sheshen",	__DIR__"shulin1",
__DIR__"shulin2",	__DIR__"shulin3",	__DIR__"shulin4",
__DIR__"yuquan",	__DIR__"yunu",		__DIR__"zhenyue",
__DIR__"shanlu1",	__DIR__"xiaolu2",	__DIR__"siguoya",
__DIR__"baichi",	__DIR__"laojun",	__DIR__"houtang",
__DIR__"celang3",	__DIR__"celang4",
});

void create()
{
        set("short", "����");
        set("long",@long
�����ǻ�ɽ�����һƬ�����֣������û�к����֣���ǧ��Ҫ�ڴ˵ؾ�
������˵����ǿ����û�����١�ɱ�˵����龭��������
long);
        set("exits",([
		"west" : __DIR__"shulin3",
	        "north" : __DIR__"shulin2",
		"east" : __DIR__"shulin1",
	]));
	setup();
}

void init(object me)
{
	object target, *living, ob, name1, ling;
	string objwhere, str;
	int i, j;

	me = this_player();
	name1 = me->query("id");
	ling = present("ling pai", me);

        if( ! (present("mengmian ren", environment(me)) ) 
	 && (int)me->query_temp("hs/jobji", 1)==1 
	 && (int)me->query_temp("hs/have", 1)==0
	 && ling
	 && (int)ling->query_temp("done", 1) < 2
	 && !(ling->query_temp("hsjob") != name1 )
	 &&  random(10) > 3 ) {

		living = livings();
		for (i=0;i < sizeof(living);i++){
			j = random(sizeof(living));
			if (j <= 1 || j == sizeof(living)-1) continue;
			if(check(living[j]) ){
				target = living[j];
				str = environment(target)->query("short");
				if( str == "��ɮ��"
				 || str == HIR"������"NOR
				 || str == "��շ�ħȦ" ) continue;
				if( get_place(base_name(environment(target)))!="" )
					break;
			}
		}

		ob=new(__DIR__"npc/mmr");
		ob->set("long", ob->query("long")+ "�������Ǹղ�����"+me->query("name")+"("+capitalize(me->query("id"))+")���Ƶ��ˡ�\n");
		ling->move(ob);
		me->set_temp("hs/have", 1);
		ling->set_temp("mmr", name1);
		ob->set_temp("mmr", name1);

		if (me->query("combat_exp", 1) > 2000000
		 && ling->query_temp("done", 1) > 0
		 && target ) {
			ob->move(environment(target));
			me->set_temp("hs/power", 1);
			message_vision(HIW "\n" + msg1[random(sizeof(msg1))] +
				msg2[random(sizeof(msg2))] + 
				msg3[random(sizeof(msg3))] + "һ��������" +
				msg4[random(sizeof(msg4))] + 
				"$N�����ƣ���" HIY +get_place(base_name(environment(target)))+ str +
				HIW + msg5[random(sizeof(msg5))] + "��ȥ��\n\n" NOR, me);
			return;
		}
		else {
			objwhere = names[random(sizeof(names))];
			ob->move(objwhere);
			message_vision(HIW "\n" + msg1[random(sizeof(msg1))] +
				msg2[random(sizeof(msg2))] + 
				msg3[random(sizeof(msg3))] + "һ��������" +
				msg4[random(sizeof(msg4))] + 
				"$N�����ƣ���" HIY + objwhere->query("short") + 
				HIW + msg5[random(sizeof(msg5))] + "��ȥ��\n\n" NOR, me);
		}
	}
}

string *no_kill_list = ({
	"mu ren", "jin ren", "yin ren", "zhong shentong", "zhu cong", "shi ren", "huo du","he shiwo"
});

int check(object ob)
{
	object room;
	string room_name;

	if(!objectp(ob)
	 || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
	 || ob->query("env/invisibility")
	 || ob->query("no_quest")
	 || member_array(ob->query("id"), no_kill_list) != -1
	 || userp(ob)
	 || ob->query("attitude")=="aggressive"
	 || ob->query("have_master")
	 || !objectp(room=environment(ob))
	 || room->query("outdoors") == "���ش��"
	 || strsrch(room_name = file_name(room),"/d/") != 0
	 || strsrch(room_name, "/d/wizard/") == 0
	 || strsrch(room_name, "/d/wuguan/") == 0
	 || strsrch(room_name, "/d/death/") == 0
	 || strsrch(room_name, "/d/mingjiao/lsd/") == 0
	 || strsrch(room_name, "/d/mingjiao/bhd/") == 0
	 || strsrch(room_name, "/d/huashan/") == 0
	 || strsrch(room_name, "/d/village/") == 0
	 || strsrch(room_name, "/d/shaolin/fumoquan") == 0
	 || strsrch(room_name, "/d/baituo/") == 0
   || strsrch(room_name, "/d/xiakedao/") == 0
   || strsrch(room_name, "/d/xiaoyao/") == 0
   || strsrch(room_name, "/d/quanzhen/") == 0
   || strsrch(room_name, "/d/wugong/") == 0)
	 return 0;
	return 1;
}

string get_place(string str)
{ 
        string *place = explode(str, "/");

        str = "";
        if(place[0] == "d")
                switch(place[1]){
//			case "baituo":          str = "�������ɽ";     break;
//			case "beijing":         str = "����";           break;
//			case "cangzhou":        str = "�ӱ�����";       break;
//			case "changan":         str = "��������";       break;
			case "chengdu":         str = "�Ĵ��ɶ�";       break;
			case "city":            str = "�������ݳ�";     break;
			case "dali": 
				switch(place[2]) {
					case "daliwest":        str = "�������";       break;
					case "dalisouth":       str = "�������";       break;
					case "dalieast":        str = "����Ƕ�";       break;
					case "wuliang":         str = "��������ɽ";     break;
					case "dlhg":            str = "����ʹ�";       break;
					case "wangfu":          str = "��������";       break;
					case "yuxu":            str = "���������";     break;
					default :               str = "���ϴ����";     break;
				}
				break;
			case "death":           str = "ʮ�˲����";     break;
			case "emei":            str = "�Ĵ�����ɽ";     break;
			case "fairyland":       str = "����ɽ��";       break;
			case "foshan":          str = "�㶫��ɽ��";     break;
			case "fuzhou":          str = "�Ͻ�����";       break;
			case "gb":              str = "ؤ��ֶ�";       break;
			case "gumu": 
				switch(place[2]) {
					case "jqg":             str = "�����";         break;
					case "xuantie":         str = "��������";       break;
					default :               str = "���Ϲ�Ĺ";       break;
				}
				break;
			case "hengshan":        str = "������ɽ";       break;
			case "hj":              str = "����ؽ�";       break;
/*                      case "hmy":
                                switch(place[2]) {
                                        case "pingding":        str = "ɽ��ƽ����";     break;
                                        default:                str = "��ľ��";         break;
                                }
                                break;
*/			case "huanghe":
				switch(place[2]) {
					case "yyd":             str = "�ƺ�����";       break;
					default :               str = "�ƺӵش�";       break;
				}
				break;
			case "huashan":         str = "������ɽ";       break;
			case "hz":              str = "���Ϻ���";       break;
			case "jiaxing":         str = "���ϼ���";       break;
//			case "kunlun":          str = "����ɽ��";       break;
//			case "lanzhou":         str = "��������";       break;
//                      case "meizhuang":       str = "����÷ׯ";       break;
			case "miaojiang":       str = "�����置";       break;
			case "mingjiao": 
				switch(place[2]) {
					case "hdg":             str = "���պ�����";     break;
					case "hhd":             str = "��������";     break;
					case "lsd":             str = "�������ߵ�";     break;
					default :               str = "��������";       break;
				}
				break;
			case "mr":		str = "����Ľ��";       break;
			case "nanyang":         str = "������Ҽ�";     break;
			case "ningbo":          str = "��������";       break;
			case "putian":          str = "��������";       break;
			case "shaolin":         str = "��ɽ����";       break;
			case "sld":             str = "����������";     break;
			case "songshan":        str = "������ɽ";       break;
			case "suzhou":          str = "�����س�";       break;
			case "taishan":         str = "ɽ��̩ɽ";       break;
			case "tanggu" :         str = "�������";       break;
			case "thd": 
				switch(place[2]) {
					case "niujia":          str = "����ţ�Ҵ�";     break;
					case "guiyun":          str = "̫������ׯ";     break;
					default:                str = "�����һ���";     break;
				}
				break;
//			case "tianshan":        str = "������ɽ";       break;
			case "tiezhang":        str = "��������ɽ";     break;
			case "tls":             str = "����������";     break;
			case "village":         str = "����С��";       break;
			case "wizard":          str = "��������";       break;
			case "wudang":          str = "�����䵱ɽ";     break;
			case "wuguan":          str = "�������";       break;
			case "xiangyang":       str = "��������";       break;
                        case "xingxiu": 	str = "�������޺�";     break;
			case "xueshan":		str = "������ѩɽ";     break;
	}
	return str;
}
