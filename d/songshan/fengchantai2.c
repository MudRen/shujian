// Room: /u/swl/songshan/fengchantai.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"����̨"NOR);
        set("long", @LONG
����̨Ϊ����ʯ������ÿ���ʯ����ü���ƽ��������ۻ�Ϊ�˼���
�븣����֪��ʹ����ʯ����ʼ�ɴ˾޹������������ǿ���������ǧ�˵Ĺ�
���������ڴˣ������������ܷ塢С�ܷ塢˫���塢����������������
������ɽ��������������Ÿ�����³��δ�ˡ��ľ��䡣
LONG);
        set("exits", ([ 
            "southdown" : __DIR__"peitian-fang",
   
        ]));
        set("objects", ([ 
 //  CLASS_D("songshan") + "/zuo2" : 1,
            __DIR__"npc/ssdizi" : 3,
        ]));
        set("outdoors", "��ɽ");
        setup();
        
}

int do_enter(string arg)
{
        mapping fam;
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="ri" ){
 if((fam = me->query("family")) && fam["family_name"] == "��ɽ��" ) {
               message("vision",me->name() + "�������·�,����շ����˹�ȥ��\n",environment(me), ({me}) );
               me->move("/d/songshan/guanrifeng");
               message("vision",me->name() + "�ӷ���̨���˹�����\n",environment(me), ({me}) );
               return 1;
           }
           else return notify_fail("�Ǳ�̫���ô�,�㲻��ɹ����?��\n");
        }       
}

void init()
{
        
        add_action("do_enter","guan");
        
}