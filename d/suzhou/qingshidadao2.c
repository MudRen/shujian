inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long",@long
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С�����ң��������ɽչ���������ǰ��
long);
set("outdoors", "suzhou");
set("exits",([
"north" : __DIR__"qingshidadao1",
"south" : __DIR__"hubiandadao",
]));
set("coor/x",120);
  set("coor/y",-320);
   set("coor/z",0);
   setup();
}