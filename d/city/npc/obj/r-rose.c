// r-rose.c ��õ��
// update by cool

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(RED "��õ��" NOR, ({ "red rose", "rose" }));
        set("weight", 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIR "һ���͸����˵ĺ�õ�壬������һ˿���顣\n" NOR);
set("value", 15000);
//              set("wear_msg", HIM "$N����һЦ���ѻ������ڷ����ϣ�������Ů�·���\n" NOR);
//              set("remove_msg", HIM "$N�ѻ����ӷ���ȡ�£����������ţ����ػ��С�\n" NOR);
//              set("armor_prop/armor", 10);
        }
        setup();
}

void init()
{
       add_action("come_life","wen");
       call_out("dest", 1800);
}
        
int come_life(string arg)
{
      object me;
      me=this_player();

      if(!arg) return 0;
      if(arg == "rose" || arg == "red rose" ){
        message_vision("$N��Сָ������ס��õ�壬����������������š�\n",me);
        tell_object(me, HIY "�š�����������������ѽ��\n" NOR);
      }
      return 1;
}

void dest()
{
      object me;
      me=this_player();
        if (!me) return;
      message_vision("$N���еĺ�õ�彥����ή�ˡ�\n",me);
      destruct(this_object());
}
