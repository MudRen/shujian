// pt.c
// ƽ̨
inherit ROOM;
void create()
{
	set("short","ƽ̨");
	set("long",@long
������һ����Ȼ���ɵ�ƽ̨������һ�����ݣ����ݵ�������д�š���
���ӡ������֣��������˲��ٻ��ݡ�
long);
	set("exits",([
	    "east" : __DIR__"zl2",
            "enter" : "/d/sld/jitan",
//          "enter" : __DIR__"xfj",
]));
	set("outdoors", "������");
        set("coor/x",470);
  set("coor/y",430);
   set("coor/z",80);
   setup();
}
	    	
