// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/changan/duchang2
// by system_3cat 7/5/1997
inherit ROOM;


void create()
{
  set ("short", "������");
  set ("long", @LONG

�������һ�����������м����һ�����̡��Ŀ������۾�������¶ġ�
��ϯ��һλ���ӣ����ﲻ����Ū��һ�������������������ׯ����

ǽ�Ϲ���һ���ң�����д�ţ�
    ͷ�ʣ�������ÿ�ο���ǰȷ����      ��һӮ��ʮ��
    ˫�ԣ���������ͬ����Ϊż����      ��һӮʮ��
    ���ǣ�����֮��Ϊ�ߣ�              ��һӮ��
    ɢ�ǣ�����֮��Ϊ�����壬�ţ�ʮһ����һӮ��

�ҽ���һ������(paizi)��

LONG);

  set("item_desc",([
    "paizi" : "Ѻͷ������ gutou tc <amount> <money>\n"+ 
              "Ѻ˫������ gutou sd <amount> <money>\n"+ 
              "Ѻ�������� gutou qx <amount> <money>\n"+ 
              "Ѻɢ������ gutou sx <amount> <money>\n" 
  ])); 

  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"chat-dc1",
  ]));

  setup();
}
//�Ǿ���
int is_mirror() { return 1; }
