inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long",@long
ʯ����̫����һ����½֧����λ�����ݳ��ϴ���ʱ��Խ�����⣬���ɽ
´����ʯ������ͨ���գ�����ʯ�������������Ϸ�ɽ��ɽ�������Ϸ�������
�ı�����ߴ��Խ���ţ������е���Խ����½��Խ��Ϫ����������ʼ����
����ĩ����д��š�
long);
set("outdoors", "suzhou");
set("exits",([
"south" : __DIR__"tianpingshan",
"west" : __DIR__"xingchunqiao",
]));
set("coor/x",110);
  set("coor/y",-270);
   set("coor/z",0);
   setup();
}
