#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
  set_name(HIW"�ٱ�ذ��"NOR, ({ "bishou", "bi shou", "dagger" }) );
  set("long", "κ̫��ا����ٱ�ذ��������һ���Ƽ������Ի��գ�������Ƴ��գ���Ի���ģ�����״�����ģ���Ի���ۡ�\nʫԻ������ѧ������������Գ����\n����ҷ������ذ�ײ���衣\n�����ٷ��£�Ю�����۷硣\n");
  init_dagger(80);
  set("unit", "��");
  set("no_sell", 1);
  set_weight(600);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 60000);
    set("material", "metal");
  }
  set("wield_msg","$N��ָ�ᵯ��һ��$n������Ϣ�ĳ��������С�\n");
  set("unwield_msg", "$N�����е�$n�ջ����С�\n");
  setup();
}

