// /u/cool/tls/wangxueting.c
// 1997.2.13

#include <ansi.h>
#include <room.h> 
inherit ROOM;
string tree(object);
void create()
{
  set("short","��ѩͤ");
  set("long",@LONG
����һ��Сͤ�ӣ�ͤ�߳���һ�ÿ���������ɽ�����и����ڣ���
˵�ǹ�ȥ������ɮ���޵ĵط�������ɽ�����䣬�㲻�ɵĴ��˸�������
����Ҳ��ʼ������������ǸϿ���ȥ�ɡ�
LONG);

     set("outdoors", "������");
     set("exits",([
           "southdown" : __DIR__"fqg",
           "down" : __DIR__"wfd",
     ]));
     set("item_desc", ([
        "����" : (: tree :),
        "tree" : (: tree :),
        "shu" : (: tree :),
     ]));
     set("coor/x",-390);
  set("coor/y",-250);
   set("coor/z",40);
   setup();
}


string tree(object me)
{   
    if((int)me->query_skill("kurong-changong", 1) < 40)
        return  "����һ��������\n";
    if((int)me->query_skill("kurong-changong", 1) >= 40)
        return  "����һ������,����ϸ���˿�����������������֣�һ����������ˣ�������ߵ����ɻ���������Ҷ��\n"; 
}

void init()
{
	add_action("do_jingzuo","jingzuo");	
        add_action("do_jingzuo","����");	
}

int do_jingzuo()
{
	object me = this_player();
       if ( (int)me->query_skill("kurong-changong", 1) < 40 )
               return notify_fail("�������������붳������\n");
        if ( (int)me->query_skill("kurong-changong", 1) > 120 )
               return notify_fail("�㿴����ȥ������������ȥҲûʲô�ջ��ˡ�\n");
       if (me->query_skill_mapped("force") != "kurong-changong")
               return notify_fail("�����ڵ��ڹ����ԡ�\n");
       if ( (int)me->query_skill("buddhism", 1) < 120 )
               return notify_fail("�㿴�˰��죬�������ѧ����̫ǳ��û��ʲô��ᡣ\n");
       if ( (int)me->query("jing")<30) 
        { write("��̫���ˣ�����Ъ�����ж��ɣ�\n");
        return 1;
         }
   
	message_vision("$N������ð�ݰ��ٵ��������㰵ӡ�𷨣�����������˼��\n", me);
       	me->receive_damage("jing", 30);
              me->receive_damage("jingli", 10); 
		me->improve_skill("kurong-changong", (int)me->query("int"));
	return 1;
}