inherit ROOM;

void create()
{
        set("short", "�����䳡-����̨");
        set("long",@LONG
����̨��һ������ƽ̨��������ɮ����ϰ���յĵط���̨��
����ľ׮��÷��׮��ɳ����ɳ���������ʩ�͸���ɮ������������
�����ɮ������һ���໥�д衣
LONG);
        set("outdoors","dali");
        set("exits", ([
               "northup" : __DIR__"longxiang1",
           
       	]));
        set("coor/x",-400);
  set("coor/y",-330);
   set("coor/z",20);
   setup();
}
