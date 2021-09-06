// yangzhou/jiulou2.c
// By snowman@SJ 27/05/2000

#include <ansi.h>
inherit ROOM;
string *cnumber = ({ "��","��","��","��","��","��","��","��","��","��" });

string look_juanbo();

void create()
{
    	set("short", "��������¥");
	set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ������߳Ժȱ�
�����ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�����¥����һ��, �Ӹ�������������
ֻ�����Ŀ��������������������������, �̲������������ǳ�ɽ���룬����
����Կ�����¹��Ժ�ĺ�ͥ���������˼������ˣ��������䣬����һЩΧ��һ
�ž�(juanbo)��������ʲô��
LONG);
	set("objects", ([
		__DIR__"npc/shusheng" : 1,
	]));
	set("map_link_room", __DIR__"jiulou");
	set("item_desc",([
//		"juanbo" : "һ�ž���������������д����С�֡�\n",
        	"juanbo" : (: look_juanbo :),
        ]));
	set("exits", ([
		"down" : __DIR__"jiulou",
	]));
	setup();
}

string look_juanbo()
{
	mapping artnames = "/cmds/usr/artname"->query_artnames();
      	string *key2, arg, str = "\n", *key = ({ });
      	int i, j;

      	arg = "\t       ";      	

      	if (!artnames)
      		return "\nĿǰ��û�й����κ��˵����顣\n���ƾ�(artname)�µ���ţ������ͬ���еģ�Ҳ������һ��������ͬ����š� \n\n";      	
      	key = keys(artnames);
      	if (!sizeof(key) || sizeof(key) < 1 )
      		return "\nĿǰ��û�й����κ��˵����顣\n���ƾ�(artname)�µ���ţ������ͬ���еģ�Ҳ������һ��������ͬ����š� \n\n";

      	str = "Ŀǰ���������飺"
	+"\n�������������ө������������ө����������ө������������ө����������ө������������ө�����������"
	+"\n��  ����    ��   ��  ��   ��  ��ͬ��  ��   ��  ��   ��  ��ͬ��  ��   ��  ��   ��  ��ͬ��  ��"
	+"\n�ĩ����������ة������������ة����������ة������������ة����������ة������������ة�����������";

      	for( i = 0; i < sizeof(key); i++ ){
      		str += sprintf("\n��%-2s"CYN"%-8s"NOR"��\t\t\t\t\t\t\t\t\t\t  ",cnumber[i], capitalize(key[i]) );
      		key2 = keys(artnames[key[i]]);
      		for( j = 0; j < sizeof(key2); j++ ){
      			if ( j%3 == 0 ) str += "��\n��\t    ";
      			str += sprintf("   %-10s      "HIW"%3d"NOR"    ",key2[j], sizeof(artnames[key[i]][key2[j]])/2 );
      			if ( j > sizeof(key2)-2 ){
      				switch(j%3){
					case 0: str +="\t\t\t\t\t\t\t  ��"; break;
					case 1: str +="\t\t\t  ��"; break;
					case 2: str +="��"; break;
					default: break;
				}
			}

      		}
      		str += "\n�ĩ�����������������������������������������������������������������������������������������";
      	}

      	str += "\n�����ƾ�(artname)�µ���ţ������ͬ���еģ�Ҳ������һ��������ͬ����š�                   ��"
    	      +"\n��������������������������������������������������������������������������������������������\n";
    	return str;
}

int get_object(object ob)
{
	if( userp(ob) ) return 1;
	return 0;
}

int valid_leave(object me, string dir)
{
	object *inv = deep_inventory(me);
	object *obj;          

	if( dir=="up" && (!me->query("oldsj") || me->query("oldsj")>=2 ) && !mapp(me->query_temp("gift_change")) )
		return notify_fail("�������Ӵ���ͣ��㻹�ǻ�ȥ�ɡ�\n");

	obj = filter_array(inv,(:get_object:));
	if( sizeof(obj) && dir == "up" )
		return notify_fail(HIR"����ͻȻ���������������������� BUG �޸����ԣ���¼�ڰ��ȴ�������\n"NOR);

	return ::valid_leave(me, dir);
}
