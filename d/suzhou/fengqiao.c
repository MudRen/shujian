inherit ROOM;

void create()
{
        set("short", "����");
        set("long",@long
�µı�����һ���ſ׳ʰ�Բ�ĵ���ʯ��---���ţ��������˺ӵķ����塣
�ŵĶ���ʯ����أ�����׻��أ�����أ��ϳ��������ء�
long);
set("outdoors", "suzhou");
set("exits",([
"north" : __DIR__"tielingguan",
"south" : __DIR__"hanshidian",
]));
set("coor/x",60);
  set("coor/y",-200);
   set("coor/z",-10);
   setup();
}
