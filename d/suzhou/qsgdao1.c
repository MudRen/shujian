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
"south" : __DIR__"qsgdao",
"southwest" : __DIR__"qsgdao2",
]));
set("coor/x",120);
  set("coor/y",-260);
   set("coor/z",0);
   setup();
}
