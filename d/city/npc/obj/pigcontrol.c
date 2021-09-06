// ʥ��������
// created by campsun 2003/12/22
#include <ansi.h>

inherit ITEM;
string get_place(string str);
object get_rnd_place();
int check(object);

int do_start();

void create()
{
    set_name(CYN "�������" NOR, ({ "control"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ʥ����Ŀ�������ÿ��һ�ν������ʮ��ֻ��ͬ���ɵ�ʥ����(Start)��\n");
		set("value", 10);
		set("no_give",1);
		set("no_drop",1);
		set("qiao",1);
		set("egg",1);
		set("material", "paper");
             }
	setup();
}
void init()
{
   	add_action("do_start", "start");
}

int do_start()
{
	int i;
	object where;
	object piggy;
	string *str_menpai = ({ "wd","hs",
							"ss",
							"gb","tz",
							"dls","mr",
							"sld","xx",
							"em","mj",
							"thd","tls",
							"sl",
						});
	string *str_gumu = ({"/d/gumu/gmzt",
						"/d/gumu/gmqt",
						"/d/gumu/gmht",
						"/d/gumu/gmqs",
						"/d/gumu/jianshi",
						"/d/gumu/fang",
						"/d/gumu/yaofang",
						"/d/gumu/shitou",
						"/d/gumu/lgf",
						"/d/gumu/gmcc",
						"/d/gumu/gmlg2",
						"/d/gumu/gmlg1",
						"/d/gumu/gmlg5",
						"/d/gumu/gmlg4",
						"/d/gumu/gmqc",
						"/d/gumu/rukou",
						"/d/gumu/guoyuan",
						"/d/gumu/shanpo",
						"/d/gumu/shanpo1",
						"/d/gumu/xuanya",
					});
	object me,ob;
	me=this_player();
	ob=this_object();
	for (i=0;i<sizeof(str_menpai);i++)
	{
		piggy = new("/d/city/npc/pig");
		piggy->set("party",str_menpai[i]);
		where = get_rnd_place();
		piggy->move(where);
		write(piggy->query("id") +" " + base_name(where) + "\n");
	}
	piggy = new("/d/city/npc/pig");
	piggy->set("party","gm");
	i = random(sizeof(str_gumu));
	if(!( where = find_object(str_gumu[i])) )
		where = load_object(str_gumu[i]);
	piggy->move(where);
	write(piggy->query("id") +" " + base_name(where) + "\n");	
	return 1;

}

object get_rnd_place()
{
	object *living;
	object target,objwhere;
	string str;
	int i,j;
    living = livings();
    for (i=0;i < sizeof(living);i++){
    	j = random(sizeof(living));
        if (!j || j == sizeof(living) -1) continue;
        if(check(living[j]) ){
        	target = living[j];
            objwhere = environment(target);
            str = objwhere->query("short");
            if (!sizeof(objwhere->query("exits"))
            	|| str == "��ɮ��"
                || str == HIR"������"NOR
                || str == "��շ�ħȦ" ) continue;
                if( get_place(base_name(environment(target)))!="" ) break;
        }
    }
    return environment(target);
}

string *no_kill_list = ({
         "mu ren", "jin ren", "yin ren", "zhong shentong", "zhu cong", "shi ren", "huo du","he shiwo"
});

string get_place(string str)
{
        string *place = explode(str, "/");

        str = "";
        if(place[0] == "d")
                switch(place[1]){
                        case "baituo":    str = "�������ɽ";  break;
                        case "hj":      str = "����ؽ�"; break;
                        case "mingjiao":  str = "��������"; break;
                        case "shaolin":   str = "����"; break;
                        case "songshan":  str = "��ɽ"; break;
                        case "wudang":    str = "�䵱ɽ"; break;
                        case "xingxiu":   str = "���޺�"; break;
                        case "city":      str = "���ݳ�"; break;
                        case "emei":      str = "����ɽ"; break;
                        case "fuzhou":    str = "����"; break;
                        case "jiaxing":   str = "����"; break;
                        case "taishan":   str = "ɽ��̩ɽ"; break;
                        case "dali":      str = "�����"; break;
                        case "tls":       str = "������"; break;
                        case "tiezhang":  str = "����ɽ"; break;
                        case "kunlun":    str = "";break;
                        case "fairyland": str = "��������ɽ"; break;
                        case "gumu":      str = ""; break;
                        case "chengdu":   str = "�ɶ�"; break;
                        case "huashan":   str = "��ɽ"; break;
                        case "xiangyang": str = "����"; break;
                        case "xueshan":   str = "��ѩɽ"; break;
                        case "wizard":    str = ""; break;
                        case "death":     str = ""; break;
                        case "gaibang":   str = "ؤ��ֶ�"; break;
                        case "hz":      str = "����"; break;
                        case "village":   str = "����С��"; break;
                        case "wuguan":    str = "�������"; break;
                        case "thd":       str = "�һ���"; break;
                        case "gaibang":   str = "ؤ��ֶ�"; break;
                        case "mr":      str = "������"; break;
                        case "suzhou":    str = "�����س�"; break;
                        case "sld":       str = "����������"; break;
        }
        return str;
}


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
         || room->query("no_fight")
         || room->query("outdoors") == "���ش��"
         || room->query("short") == "���º�ȭ��"
         || strsrch(room_name = file_name(room),"/d/") != 0
         || strsrch(room_name, "/d/wizard/") == 0
         || strsrch(room_name, "/d/wuguan/") == 0
         || strsrch(room_name, "/d/death/") == 0
         || strsrch(room_name, "/d/kunlun/") == 0
         || strsrch(room_name, "/d/mingjiao/lsd/") == 0
         || strsrch(room_name, "/d/mingjiao/bhd/") == 0
         || strsrch(room_name, "/d/wudang/") == 0
         || strsrch(room_name, "/d/shaolin/liwu") == 0
         || strsrch(room_name, "/d/shaolin/houyuan") == 0
         || strsrch(room_name, "/d/huashan/jiabi") == 0
         || strsrch(room_name, "/d/shaolin/fumoquan") == 0
         || strsrch(room_name, "/d/shaolin/xinchan") == 0
         || strsrch(room_name, "/d/mingjiao/yuanzi") == 0
         || strsrch(room_name, "/d/mingjiao/wxiang") == 0
         || strsrch(room_name, "/d/baituo/") == 0
         || strsrch(room_name, "/d/thd/") == 0
         || strsrch(room_name, "/d/sld/") == 0)
         return 0;
        return 1;
}