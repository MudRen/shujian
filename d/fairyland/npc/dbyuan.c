// dabaiyuan.c
// By jpei
// Modify By River@SJ

#include <ansi.h>
inherit NPC;
int do_cut(string arg);
void dest();
void create()
{
        set_name(HIW"���Գ"NOR, ({ "da baiyuan", "da", "baiyuan", "yuan" }) );
        set("race", "Ұ��");
        set("age", 54);
        set("long", "һֻ�����Ű�ë����Գ������ŧѪģ��������һ���󴯡�\n��ϸ���ŷ��֣��������ϵ�ͻ���Ǳ��������߷���ʲô��ȥ��������Ҫ����֮�����С�\n");

        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 100000);
    
	set_temp("apply/attack", 250);
        set_temp("apply/defense", 250);
        set_temp("apply/damage", 250);
        set_temp("apply/armor", 250);

        setup();
	if (clonep()) call_out("disappear",120);
}

void init()
{
	add_action("do_cut", ({"cut", "sever", "ge", "heal", "zhi", "yizhi", "zhiliao"}));
}

void disappear()
{
	message_vision("$N������ã�Ҳû���˾������������ȥ�ˡ�\n", this_object());
	destruct(this_object());
}

int do_cut(string arg)
{
	object thread, yaocao,book;
	object me = this_player();
        if (me->is_busy() || me->is_fighting())
             return notify_fail("����æ���أ�\n");
	if (id(arg)){
             if(!me->query_temp("monkey_help"))
                return notify_fail("��С�ﶼû�Ȼ�㻹���ʲô��\n");
             if( me->query_skill("medicine", 1) < 120)
                return notify_fail("�㿴�˿���Գ�����ƣ��о��Լ�ҽ��������ֻ��̾�˿�����\n");
	     if(!present("sharp rock", me))
		return notify_fail("��ϧ����ͷû�е�����\n");
	     if(!present("fish bone", me) || !thread = present("xi si", me))
		return notify_fail("��ϧ����ͷû�����ߡ�\n");
	     if(!yaocao = present("yao cao", me))
		return notify_fail("��ϧ����ͷû�в�ҩ��\n");
	     thread->add_amount(-1);
	     yaocao->add_amount(-1);
             me->delete_temp("monkey_help");
             remove_call_out("dest");
             call_out("dest", 1, this_object());
             if(me->query("jiuyang/mai") || !me->query("jiuyang/zhang"))
                return notify_fail(HIY"\n���ü�ʯ�������Գ�Ǹ��Ϸ첹��֮����ԭ�����ϴ��˿�û�з�ã����Ѿ������ˡ�\n"+
               	                      "����������룬��Ƥ��ɵ�ϸ˿���ߣ��������˿ڣ����Ѳ�ҩ�����˸��������˴���\n\n"NOR);
             book = unew("/d/fairyland/obj/jiuyang");
             if(!clonep(book)){                
            	write(HIY"\n���ü�ʯ�������Գ�Ǹ��Ϸ첹��֮����ԭ�����˿��ϴ�û�з�ã����Ѿ������ˡ�\n"NOR);
	        write(HIY"����������룬��Ƥ��ɵ�ϸ˿���ߣ��������˿ڣ����Ѳ�ҩ�����˸��������˴���\n"NOR);
	        if(!me->query("jiuyang/baiyuan"))
	        {
	        	new_ob("../obj/pantao")->move(me);
	        	return notify_fail(HIY"��Գʮ�ָм��㣬������һ�������Ĵ���ң�Ȼ�����ˡ�\n\n"NOR);
	        }
	        return notify_fail("");
             }
             if(clonep(book) && book->violate_unique()){
                destruct(book);                
            	write(HIY"\n���ü�ʯ�������Գ�Ǹ��Ϸ첹��֮����ԭ�����˿��ϴ�û�з�ã����Ѿ������ˡ�\n"NOR);
	        write(HIY"����������룬��Ƥ��ɵ�ϸ˿���ߣ��������˿ڣ����Ѳ�ҩ�����˸��������˴���\n"NOR);
	        if(!me->query("jiuyang/baiyuan"))
	        {
	        	new_ob("../obj/pantao")->move(me);
	        	return notify_fail(HIY"��Գʮ�ָм��㣬������һ�������Ĵ���ң�Ȼ�����ˡ�\n\n"NOR);	        		        	
	        }
	        return notify_fail("");	        
             }
	     write(HIY"\n���ü�ʯ�������Գ�Ǹ��Ϸ첹��֮����ֻ�����澹����һ���Ͳ���������һ������һ�׾��顣\n"NOR);
	     write(HIY"����������ϸ��飬æ���뻳�С�Ȼ����������룬��Ƥ��ɵ�ϸ˿���ߣ���ǿ�����˰�Գ���˿ڡ�\n"NOR);
	     if(!me->query("jiuyang/baiyuan"))
	     {	     
	     	new_ob("../obj/pantao")->move(me);
	     	write(HIY"�����Ѳ�ҩ�����˸��������˴�����Գʮ�ָм��㣬������һ�������Ĵ���ң�Ȼ�����ˡ�\n\n"NOR);
	     }
             me->set("jiuyang/baiyuan",1);
             book->set_temp("jiuyang",me->query("id"));
	     book->move(me);
	     
             return 1;
	}
	return 0;
}

void dest()
{
        destruct(this_object());
}
