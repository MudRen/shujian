inherit ROOM;

void create()
{
set("short", "��ɽׯ");
        set("long",@long
�ڻ���ɽ���������ɽׯ����һ���ϴ���辰԰��������Ϊ���غ���
�ϡ���Բ�أ�������������꣬����Ϊ���辰֮�����������辰Ϊ������ϼ
ε������ʯ�辰����һ���İٶ����ȸ÷��׮�辰�������辰�������е���
Ʒ��Բ�ھ�ɫ�������ĸ�԰����Ȥ��
long);
set("outdoors", "suzhou");
set("objects",([
__DIR__"npc/tangzi" : 2,
]));
set("exits",([
 "east" : __DIR__"toushanmen",
"north" : __DIR__"caizhu" ,
"westup" : __DIR__"hanhanquan",
"eastup" : __DIR__"shijianshi",
]));
set("incity",1);
	setup();
}
