inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long",@long
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С�����ͨ������ɽ������ĺ��ߴ��
ͨ����������Ĺ���Ľ�����ҡ�
long);
set("outdoors", "suzhou");
set("exits",([
"north" : __DIR__"lingyanshan",
 "east" : "/d/mr/hubian",
"south" : __DIR__"qingshidadao1",
]));
set("coor/x",120);
  set("coor/y",-300);
   set("coor/z",0);
   setup();
}
