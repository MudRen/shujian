//Room: /d/huashan/qianting.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "ǰ��");
        set("long", @LONG
�ϵ�ɽ������Ȼ��ǰһƬ�������ܶ໪ɽ�ɵ��Ӹ���æµ�š��ϱߵķ���
���Ϲ���һ���ң�����������֡�������Ϊ������
LONG );
        set("exits",([
	"northdown" : __DIR__"taijie",
	"south" : __DIR__"zhengqi",
	"west" : __DIR__"celang1",
	"east" : __DIR__"celang2",
	]));

	set("outdoors", "��ɽ" );

        set("coor/x",80);
  set("coor/y",-10);
   set("coor/z",80);
   setup();

        "/clone/board/huashan_b"->foo();
}
