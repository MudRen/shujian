#include <ansi.h>
inherit ROOM;
void create()
{
       set("short", "�ּ�С·");
       set("long",@LONG
������һ��Ƭ��ɭ�֣�һ�����۵�С·��Խ��䡣������û����ɽ������
�ͱڵ�Σ�գ������ѽ�Ϊƽ̹������ľ�����Ƽ䣬�ֱ���һ����ɭ���¡�����
����ľ��ֱ�������ţ����й��ɣ��Ǽ�����ǰ���������ǿ��ٹ�����ʱ��ֲ��
������Ϊ��ֲ������ʱ����Ѿã��кܶ�ķ������޳�����䡣���Ҽ����ʮ
�ֺ�Ļ�ѩ���侰ʮ��׳�ۡ�
LONG);

       set("exits",([
            "southwest" : __DIR__"xiaolu2",
            "northup"  : __DIR__"gmd",
            
       ]));
       set("coor/x",-310);
  set("coor/y",110);
   set("coor/z",90);
   set("coor/x",-310);
 set("coor/y",110);
   set("coor/z",90);
   setup();
       set("outdoors", "���̹�����");
}
//�Ǿ���
int is_mirror() { return 1; }