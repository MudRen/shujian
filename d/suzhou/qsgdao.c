inherit ROOM;

void create()
{
        set("short", "��ʯ�ٵ�");
        set("long",@long
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С�
long);
set("outdoors", "suzhou");
set("exits",([
"north" : __DIR__"qsgdao1",
"southwest" : __DIR__"tianpingshan",
]));
set("coor/x",120);
  set("coor/y",-270);
   set("coor/z",0);
   setup();
}
