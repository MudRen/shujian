// Room: /d/huashan/shulin.c
// Date: Look 99/03/25
// Modify By River@SJ 2001.11.13

inherit ROOM;

#include <ansi.h>
#include <get_place.h>

object get_where();

string* msg1 = ({
"��Ȼ","ͻȻ","�͵�","�䲻��","�䲻��",
});
string* msg2 = ({
"��������","�������",
});
string* msg3 = ({
"�ܳ�","ɱ��",
});
string* msg4 = ({
"һ�Ѷ���","����","һ����ȥ","��ȥ",
});
string* msg5 = ({
"��","����","����·","�����·",
});

string* names = ({
"/d/village/caidi",	"/d/village/shilu1",	"/d/village/shilu2",
"/d/village/shilu3",	"/d/village/shilu4",	"/d/village/caidi",
"/d/village/shilu5",	"/d/village/shilu6",	"/d/village/miaoyu",
"/d/village/caidi",	__DIR__"canglong",	__DIR__"celang1",
__DIR__"celang2",	__DIR__"chaoyang",	__DIR__"husun",
__DIR__"pubu",		__DIR__"qianchi",	__DIR__"qingke",
__DIR__"shaluo",	__DIR__"sheshen",	__DIR__"yaofang",
__DIR__"shulin1",	__DIR__"shulin2",	__DIR__"shulin3",
__DIR__"shulin4",	__DIR__"yuquan",	__DIR__"yunu",
__DIR__"zhenyue",	__DIR__"shanlu1",	__DIR__"xiaolu2",
__DIR__"siguoya",	__DIR__"baichi",	__DIR__"laojun",
__DIR__"houtang",	__DIR__"celang3",	__DIR__"celang4",
"/d/village/caidi",
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
	set("outdoors", "��ɽ");
	setup();
}

void init(object me)
{
	object ob, name1, ling;
	mixed objwhere;
	int done;
	string str;
		
	me = this_player();
	name1 = me->query("id");
	ling = present("ling pai", me);
	
	if(!ling) return;
	
	done = (int)ling->query_temp("done", 1);

        if( ! (present("mengmian ren", environment(me)) ) 
	 && (int)me->query_temp("hs/jobji", 1)==1 
	 && (int)me->query_temp("hs/have", 1)==0
	 && !me->query_temp("hs/robot")
	 && ling
	 && done < 2
	 && !(ling->query_temp("hsjob") != name1 )
	 &&  random(10) > 3 ) {
                ob=new(__DIR__"npc/mmr");
                objwhere = names[random(sizeof(names))];
                str = objwhere->query("short");
                ob->set("long", ob->query("long")+ "�������Ǹղ�����"+me->query("name")+"("+capitalize(me->query("id"))+")���Ƶ��ˡ�\n");
                if (me->query("combat_exp") > 2000000 && done > 0 && random(4) ){
                	me->set_temp("hs/power", 1);
                	objwhere=get_where();
                	if(objwhere) str= get_place(base_name(objwhere))+objwhere->query("short");
                }
                if(!objwhere) objwhere = names[random(sizeof(names))];                
                ob->move(objwhere);
                ling->move(ob);
                me->set_temp("hs/have", 1);
                ling->set_temp("mmr", name1);
                ob->set_temp("mmr", name1);
                ob->set_temp("done",done);
                ob->do_clone(ob, me);
                
                if(strlen(str)<=0 && random(3) && me->query_temp("hs/power"))
                	str = "\n"+CHINESE_D->font(str);
                
                message_vision(HIW "\n" + msg1[random(sizeof(msg1))] +
                        msg2[random(sizeof(msg2))] + 
                        msg3[random(sizeof(msg3))] + "һ��������" +
                        msg4[random(sizeof(msg4))] + 
                        "$N�����ƣ���" HIY + str + 
                        HIW + msg5[random(sizeof(msg5))] + "��ȥ��\n" NOR, me);
		tell_object(me,HIY"��һ��ץ����������ͼ�������ƣ��������������ݵö��˹�ȥ����˳�ֳ��������˵����֣�����ԭ�����������𽭺���"+ob->name()+"��\n"NOR);
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
	 || room->query("outdoors") == "���ǵ�"
	 || strsrch(room_name = file_name(room),"/d/") != 0
	 || strsrch(room_name, "/d/wizard/") == 0
	 || strsrch(room_name, "/d/wuguan/") == 0
	 || strsrch(room_name, "/d/group/") == 0
	 || strsrch(room_name, "/d/death/") == 0
	 || strsrch(room_name, "/d/mingjiao/lsd/") == 0
	 || strsrch(room_name, "/d/mingjiao/bhd/") == 0
	 || strsrch(room_name, "/d/huashan/") == 0
	 || strsrch(room_name, "/d/village/") == 0
	 || strsrch(room_name, "/d/shaolin/fumoquan") == 0
            || strsrch(room_name, "/d/xiaoyao/") == 0
   || strsrch(room_name, "/d/quanzhen") == 0
   || strsrch(room_name, "/d/menggu/") == 0
   || strsrch(room_name, "/d/xiakedao/") == 0
   || strsrch(room_name, "/d/luoyang/") == 0    
   || strsrch(room_name, "/d/beijing/") == 0
         || strsrch(room_name, "/d/baituo/") == 0)
	 return 0;
	return 1;
}

object get_where()
{
	object* living;
	object target;
	int i,j;
	string str;
	
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
	
	if(target && environment(target) ) return environment(target);
	return 0;
}