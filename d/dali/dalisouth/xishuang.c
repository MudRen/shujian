// Room: /d/dali/xishuang.c
// bbb 1997/06/10 
// update cool 98.2.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "��˫����");
	set("long", @LONG
��˫�����Ǵ���߽�һ���������ĵ����أ����׽�����֧��С�ڽ�������
�ӡ���ɳ�ӡ����󽭡������ӵȺ��������ȫ��������Ϊ����ɽɽ�أ�����Ϊ
ŭɽɽ����������߷�Ϊ����ɽ�����ʾ��顢���ڡ��º����º����������ĵ�
���ӡ���һ���޼ʵ�ԭʼɭ���ﻹ��ֳ��Ұ�󡢻�������Ϭţ����˿���ȸ��
Ϭ����������ޡ�
LONG
	);
        set("outdoors", "����");

	set("exits", ([
             "northeast" : __DIR__"xiushan",
             "east" : __DIR__"jiangnan",
	]));

	set("coor/x",-310);
  set("coor/y",-530);
   set("coor/z",0);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/xishuang",1);
      }
}

int valid_leave(object me, string dir)
{
        if ( me->query_temp("xuncheng")
         && dir == "east")
           return notify_fail("�㻹��Ѳ���أ���ϸ����������ɡ�\n");
           return ::valid_leave(me, dir);
}

