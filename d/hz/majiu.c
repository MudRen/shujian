// /u/beyond/hz/majiu.c ���
 
inherit ROOM;
void create()
{
         set("short","���");
         set("long",@long
���ǿ͵���ϵ���ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ�����Ҫ
ס�꣬����Ǿͻ����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ
������һֱ�ź򵽿��������·������жѷ������Ѳ��ϣ�������һ����ۡ�
long);
        set("outdoors", "hz");
	set("exits", ([
"west" : __DIR__"tianxiang",
	]));

/*	set("objects", ([
		__DIR__"npc/mafu" : 1,
                __DIR__"obj/ma" : 3,
	]));
*/
	set("coor/x",110);
  set("coor/y",-350);
   set("coor/z",0);
   setup();
}

