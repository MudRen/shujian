// /u/beyond/hz/yuewangmiao.c ������
#include <ansi.h>
 
 inherit ROOM;
void create()
{
set("short",RED"������"NOR);
        set("long", @LONG
���߽�������ֻ���������������񣬺�ӣ˧�����ϼ׽��ۣ�������ȭ��
���ְ�����������Ȼ�������϶˹��������ױ���������ֺ���(bian)�����
��������С����ұ������ĸ����֡����˶���λ����Ӣ�۵���׳ɽ�ӵ�һ��
�������岻�ѡ�
LONG
         );
set("no_fight",1);
        set("item_desc",([
        "bian" : "    ��        ��        ��        ɽ\n"
]));
        set("exits", ([
          "northwest" : __DIR__"baidi",
 "enter" : __DIR__"yuanmen",
"west" : __DIR__"hubian3",
"east" : __DIR__"tianxiang",
          "southeast" : __DIR__"qsddao2",  
]));
set("coor/x",90);
  set("coor/y",-350);
   set("coor/z",0);
   setup();
}
