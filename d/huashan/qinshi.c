// Room: /d/huashan/qinshi.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����������Ⱥ�����ң�����Ⱥ�ڽ������˳ơ����ӽ���������Ϊһ�������ţ�
����������ȴ���õĺܼ򵥡�����һ�Ŵ�����ֻ���ӣ�ǽ�����Ż�ױ̨��ֻ�п�ǽ
һ�ź�ľ����(desk)���Ե��������ɡ�
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"houtang",
	]));
        set ("item_desc", ([
                "desk" : 
"����һ�źܽ�ʵ�ĺ�ľ�����������ϰ��ż�ֻ�Ǻ��ʣ�ĥ��һ���ī��\n"
"����һ��δ�õİ�ֽ��\n"
        ])  ) ;

	 set("objects",([
	 	__DIR__"obj/shengzi" : 1,
	 ]));

        set("no_clean_up", 0);
	 set("indoors", "��ɽ" );

        set("coor/x",80);
  set("coor/y",-40);
   set("coor/z",80);
   setup();
}

