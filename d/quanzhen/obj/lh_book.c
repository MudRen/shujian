// Code of ShenZhou
//lh_book.c
//wsky
#include <ansi.h>
inherit ITEM;

int do_start(object me);


void create()
{
        set_name("��Ƥ����", ({ "ce zi", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL"����һ����Ƥ���ӣ�������д�š�������������׭�֣����½�����д��ȫ�泤���ӡ�\n"NOR);
                set("material", "paper");
                set("no_drop","�������������뿪�㡣\n");
                set("no_get","�������������뿪�㡣\n");
                set("no_steal", 1);
                set("unique", 1);
        set("treasure",1);
                set("value", 300000);
        }
}

void init()
{
        add_action("do_lingwu","read");
  
}
int do_lingwu(string arg)
{
        object me;
        int cost;
        me=this_player();
         if (me->is_busy())
            return notify_fail("����æ����!\n");
        
        if(arg!=this_object()->query("id")) return notify_fail("��Ҫ����ʲô?\n");
        
        if(me->query_skill("quanzhen-jianfa", 1) <100)
            return notify_fail("���ȫ�潣��������죬�޷�����Ҫ���еİ��\n");
            
        if(me->query_skill("taoism",1)<100)
        	return notify_fail("��ĵ�ѧ��Ϊ������\n");
        	
        if(me->query_skill("literate",1)<100)
        	return notify_fail("����ѧˮƽ̫��������˲ᡣ\n");
        
        if(this_object()->query("player_id")!=me->query("id"))
        {
                me->add("max_neili",-10);
                return notify_fail(HIR"��һ��֮��ֻ���������ȣ��������ۣ�˵���������ܡ�\n"NOR);

	}

        if(me->query("quest/quanzhen/sword/lianhuan")==1)
                    return notify_fail("���Ѿ�������������Ҫ��\n");
        
        if(me->query("neili")<1000||me->query("jing")<200)
                return notify_fail("�㾫�񲻼ѣ��޷������ķ��еİ��\n");
                
        cost=me->query("int");
        
        if(cost>=30)
                cost=5;
        else
                cost=35-cost;
        
        me->set_temp("lianhuan_cost",cost);
        
        message_vision(YEL"$N�ӻ�������һ��С����,ȫ���ע���Ķ��ţ���ʱ��������ıȻ���\n" NOR, me);
    	me->start_busy((: do_start:));
        return 1;

}

int do_start(object me)
{

        if(me->query_temp("lianhuan_cost")<=0)
        {
                if(random(me->query("int"))>20 && random(me->query("kar"))>16)     
                {
                        me->add("lingwu_lianhuan",1);
                        tell_object(me,HIY"�㾲�����ã��ƺ�����������������һ˿����\n"NOR);
                        
                        if(me->query("lingwu_lianhuan")>=20)
                        {
                                tell_object  (me,HIG"��ϲ������������������������ؾ��ľ�Ҫ��\n"NOR);
                                me->set("quest/quanzhen/sword/lianhuan",1);
                                me->delete("lingwu_lianhuan");
                                
                        }
                        me->set("neili",0);
                        me->set("jingli",0);
        
                }
                else
                {
                        
                        tell_object  (me,HIR"����˼����ʼ�ղ������򣬲��ɵ����д��\n"NOR);
                        me->add("neili", -me->query("max_neili")/20 );
                        me->receive_damage("jing", me->query("max_jing")/20 );
                    	
                    	if(me->query("neili")<0 || me->query("jing")<0)
                    		me->unconcious();
                   		
        	}
        
        	return 0;
        }
        me->add_temp("lianhuan_cost",-1);
        
        return 1;
}
