inherit ROOM;

void create()
{
set("short", "���");
set("long",@long
���Ǳ���ֱ��ϵ���ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ�����
Ҫס�꣬����Ǿͻ����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�
Ǭ������һֱ�ź򵽿��������·������жѷ������Ѳ��ϣ�������һ����
�ۡ�
long);
        set("outdoors", "suzhou ");
	set("exits", ([
		"south" : __DIR__"xiyuanzi",
		"east" : __DIR__"beidajie1",
	]));

/*	set("objects", ([
		__DIR__"npc/mafu" : 1,
                __DIR__"obj/ma" : 3,
	]));
*/
	set("coor/x",100);
  set("coor/y",-210);
   set("coor/z",0);
   set("incity",1);
	setup();
}

