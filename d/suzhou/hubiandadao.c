
#include <ansi.h>

inherit ROOM;


void create()
{
        set("short", "���ߴ��");
        set("long",@long
������ң��̫����ɫ���̲���ɭ��������ǧ������̫��֮�ϣ����ֵ��䣬
ǧ��һ�ڣ���Ӱ��������ͷ������Ⱥɽ��ȥ�����측ˮ����ãˮ�棬�㷫ǧ
�ţ������к���ˮ����ӡ������ϰ����ϼ����ʱ�������������������
��������
long);
set("outdoors", "suzhou");
set("objects",([
__DIR__"npc/tangzi" : 2,
]));
set("exits",([
"west" : "/d/thd/guiyun/road1",
"north" : __DIR__"qingshidadao2",
]));


    set("outdoors", "shaolin");
    set("coor/x",120);
  set("coor/y",-330);
   set("coor/z",0);
   setup();
}

