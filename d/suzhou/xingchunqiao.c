inherit ROOM;

void create()
{
        set("short", "�д���");
        set("long",@long
˳��ʯ�������߾��������д��ţ���վ���д��ŵ�ʯ���ϣ���ĿԶ����
��ˮ���죬Ⱥɽ���ѣ���Ӱ��Ӱ����������
long);
set("outdoors", "suzhou");
set("exits",([
"east" : __DIR__"shihu",
]));
set("coor/x",100);
  set("coor/y",-270);
   set("coor/z",0);
   setup();
}
