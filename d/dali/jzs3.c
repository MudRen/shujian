// Room: /d/dali/jzs3.c
// bbb 1997/06/10 
// Modify By River 98/12 
inherit ROOM;

void create()
{
	set("short", "��ɽһ��");
	set("long", @LONG
��һ�������ɽһ�ᡱ��ַ����������ɽ�Ż������顰��·���ǡ�����
�顰��ɽһ�ᡱ������ԵϪǰ�У�������Ʒʯ����Խ��ʯ���š����پ�����ʿ
�󡱣���ɽ�ȴ����з���ӿк������������εΪ׳�ۡ�
LONG
	);
        set("outdoors", "����");

	set("exits", ([
            "eastup" : __DIR__"jzs2",
            "westdown" : __DIR__"erhai",
	]));

	set("coor/x",-270);
  set("coor/y",-340);
   set("coor/z",-10);
   set("coor/x",-270);
  set("coor/y",-340);
   set("coor/z",-10);
   setup();
}
