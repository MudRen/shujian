//flowray 2005.6.20
#include <ansi.h>


inherit SPEC; 

void create()
{
	set_name (HIC"�����赨ɢ"NOR, ({"tianqi","san"}));
	
	set("long",HIW"�ɼ������赨�������Ƶ�������ҩ��\n"NOR);

	set("unit","��");
	set_weight(100);
	set("value",3000000);
        set("treasure",1);
        set("degree",1);
	set("flag","spec/tianqi");
	set("desc","�������Ƹ�����̵���֢��");
        set("credit",15);       
	setup();
}

void init()
{
	add_action("do_eat","eat");
  
}

int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
              return notify_fail("��Ҫ��ʲô��\n");

       if (me->is_busy() || me->is_fighting() ) return notify_fail("����æ���ء�\n");


        me->clear_conditions_by_type("poison");
        me->clear_condition("no_perform");
        me->clear_condition("no_exert");
        me->clear_condition("no_force");
        me->clear_condition("neishang");
        me->clear_condition("yyz_hurt");
        me->clear_condition("yzc_qiankun");
        me->clear_condition("fx_busy");
        me->clear_condition("hunyuan_hurt");
        me->clear_condition("no_enforce");
        me->clear_conditions_by_type("hurt");
	      me->clear_conditions_by_type("wound");
        message_vision(HIR"$N����һ�������赨ɢ����ϥ���ã�ֻ����һ����������Ϣ�Ե���ӿ������\n"NOR, this_player());
//        destruct(this_object());
       degree();
	     return 1;
}	 
