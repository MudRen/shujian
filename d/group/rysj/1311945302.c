// automake group room , Fri Jul 29 21:37:44 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","�ɵµ�[0;0m");
set("long","�չ�Ӷ�����������һ��������ľ޴����ң�
�������ĸ���ɫ���֡��󱻲�����
�������·���������⣬���ɵ�������Ȼ�𾴡�
������������ʮ���ߣ�����ȴ���������ߣ�
�˶˸���һ����Ϊ��̽���֮λ��
����ֱ�ڷŰ������Σ�Ϊ������������֮λ��
[0;0m");
set("exits",([
"south":__DIR__"1311945064.c","east":__DIR__"1311945406.c","west":__DIR__"1311945371.c",
]));
set("objects",([
"/d/group/obj/biaozhi.c":1,
]));
set("indoors","[1;31m��[1;34m��[1;37m���[0;0m");
set("group1","rysj");
set("group2","[1;31m��[1;34m��[1;37m���[0;0m");
setup();
setup_var();
}
