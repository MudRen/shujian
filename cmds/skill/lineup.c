// lineup.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object *lineup;
	object ob;
   if (me->query_temp("qzkj_job/finish")> 1)
   	{
   		return notify_fail("���Ѿ���ʼ������������ˣ���������δ��̫���˰ɡ�\n");
   	}	
   	   if (me->query_temp("xykm_job/finish")> 1)
   	{
   		return notify_fail("���Ѿ���ʼ�������������ˣ���������δ��̫���˰ɡ�\n");
   	}	
   	   if (me->query_temp("smy_job/finish")> 1)
   	{
   		return notify_fail("���Ѿ���ʼ��Ħ�������ˣ���������δ��̫���˰ɡ�\n");
   	}	
    if( !arg ) 
    {
        if( !pointerp(lineup = me->query_lineup()) )
            return notify_fail("�����ڲ�û�м����κ��󷨡�\n");
        write("���������еĳ�Ա�У�\n  " + implode(lineup->name(1), "\n  ") + "��\n");
        return 1;
    }
	if(arg=="refuse")
	{
		if(!me->query_temp("pending/lineup"))
			return notify_fail("���ڲ�û��������������󷨡�\n");
		ob=me->query_temp("pending/lineup");
		if(objectp(ob))
			tell_object(ob,"�Է��ܾ���������롣\n");
		me->delete_temp("pending/lineup");
		write("��ܾ��˶Է������󷨵����롣\n");
		return 1;
	}
    if( arg=="dismiss" ) 
    {
        if( !pointerp(lineup = me->query_lineup()) && !me->query_form() )
            return notify_fail("�����ڲ�û�м����κ��󷨡�\n");
        if( me->is_lineup_leader() ) 
        {
            message_vision( "$N���󷨽�ɢ�ˡ�\n", me);
        } 
        else 
        {
            message_vision( "$N���������󷨡�\n", me);
        }
        me->dismiss_lineup();
        return 1;
    }
    if( sscanf(arg, "with %s", arg)==1 ) 
    {
        if( !(ob = present(arg, environment(me)))
        	|| !living(ob)
        	|| !ob->is_character()
        	|| ob==me )
        	return notify_fail("�����˭һ����\n");

        if( ob->query_condition("killer") && ! me->query_condition("killer"))
            return notify_fail("�Է����ڱ��ٸ�ͨ�������ܼ�������󷨡�\n");

        if( ob->query_condition("qzkj_job_busy"))
            return notify_fail("�Է�����ȫ�濹�����񵹼�ʱ�У����ܼ�������󷨡�\n");
            
        if( ob->query_condition("xykm_job_busy"))
            return notify_fail("�Է����������������񵹼�ʱ�У����ܼ�������󷨡�\n");
            
        if( ob->query_condition("smy_job_busy"))
            return notify_fail("�Է�������Ħ�����񵹼�ʱ�У����ܼ�������󷨡�\n");            
            
        if( ob->query_temp("qzkj_job/finish")>1)
            return notify_fail("�Է�����ȫ�濹�������ɱ������֣����ܼ�������󷨡�\n");
            
        if( ob->query_temp("xykm_job/finish")>1)
            return notify_fail("�Է������������������ɱ�ɹ���ʿ�����ܼ�������󷨡�\n");
            
         if( ob->query_temp("smy_job/finish")>1)
            return notify_fail("�Է�������Ħ�������ɱ������ʿ�����ܼ�������󷨡�\n");

            
        if( !pointerp(me->query_lineup()) || me->is_lineup_leader() ) 
        {
		if( ob==(object)me->query_temp("pending/lineup"))
		{
		if (!ob->query_form())
			return notify_fail("�Է��Ѿ����󷨽�ɢ�ˡ�\n");
		if (!me->query_skill(ob->query_form(), 1))
			return notify_fail("�㲻��Է����󷨡�\n");
            	if( sizeof( ob->query_lineup() ) >= 
            		SKILL_D(ob->query_form())->query_limit() )
            		return notify_fail("�Է������Ѿ����㹻�������ˡ�\n");

				if( arrayp(me->query_lineup()) || me->query_form() )
            		return notify_fail("������˳���ǰ�󷨲��ܼ����µ��󷨡�\n");
            	
                if( !pointerp(me->query_lineup()) ) 
                {
                    me->set_form(ob->query_form());
			me->set_lineup_leader(ob);
                    ob->add_lineup_member(me);
                    message_vision("$N��������$n���󷨡�\n", me, ob);
                    if( me->is_fighting() && userp(me) )
                        me->start_busy(1);
                    if( ob->is_fighting() && userp(ob) )
                        ob->start_busy(1);
                }
                else 
                {
			ob->set_form(me->query_form());
			ob->set_lineup_leader(me);
                    me->add_lineup_member(ob);
                    message_vision("$N������$n����\n", me, ob);
                    if( ob->is_fighting() && userp(ob) )
                        ob->start_busy(1);
                    if( me->is_fighting() && userp(me) )
                        me->start_busy(1);
                }
                me->delete_temp("pending/lineup");
                return 1;
            } 
            else 
            {
            	if( !me->query_form())
            		return notify_fail("��û��ѡ��Ҫ���������󷨡�\n");
            	if( !ob->query_skill(me->query_form(),1) )
            		return notify_fail("�Է����������󷨣��޷����롣\n");
				if( arrayp(ob->query_lineup()) || ob->query_form() )
            		return notify_fail("�Է�ĿǰҲ�ڲ����޷�����������롣\n");
				if( ob->query_temp("pending/lineup")==me )
					return notify_fail("���Ѿ�������Է��ˡ�\n");
				if( ob->query_temp("pending/lineup") )
					return notify_fail("�Ѿ��б���������Է��ˡ�\n");
                message_vision("$N����$n����$P��" + to_chinese(me->query_form()) +"��\n", me, ob);
                tell_object(ob, YEL "�����Ը����룬���� lineup with " + me->query("id") + "��\n" NOR);
                ob->set_temp("pending/lineup", me);
                return 1;
            }
        } 
        else
            return notify_fail("ֻ���������߲ſ���������˼��롣\n");
    }
    if( sscanf(arg, "form %s", arg)==1 ) 
    {
        if( pointerp(lineup=me->query_lineup()) || me->query_form() )
            return notify_fail("����������˳���ǰ���󷨲�����֯�µ��󷨡�\n");
        if( !me->query_skill(arg, 1) )
            return notify_fail("����������û��ѧ����\n");
		if(SKILL_D(arg)->type()!="array")
            return notify_fail("�����书�����󷨡�\n");
		if( me->query_temp("pending/lineup") )
			return notify_fail("������������������룬��������Ⱦܾ��Է�������֯�µ��󷨡�\n");
        me->set_form(arg);
        me->set_temp("lineup/env",environment(me));
        call_out("check_lineup",1,me);
        message_vision(HIY"" 
        	+ "$N����������������Х������"
        	+ to_chinese(arg)
        	+ "�������������ش��˳�ȥ��\n"NOR, me );
        return 1;
    }
}


int filldata(object obj1)
{
	if(wiz_level(obj1)) return 0;
	if(!environment(obj1)) return 0;
	else return 1;
}

int check_lineup(object me)
{
	object *lineup,*enemy;
	int i,j;
    mixed *ob_list;
    int max;
	
	if( !me )
	{
   		ob_list = users();
   		ob_list = filter_array(ob_list, (: filldata :));
   		max=sizeof(ob_list);
   		for( i = 0;i<max;i++)
   		{
			lineup = ob_list[i]->query_lineup();
   			if( lineup && !lineup[0] )
   			{
   				for( j=0;j<sizeof(lineup);j++)
   				{
   					if( lineup[j] )
   					{
   						lineup[j]->set_lineup(0);
   						lineup[j]->delete_form();
   						lineup[j]->remove_lineup_effect();
   					}
   				}
   			}
   		}
	    return 1;
	}

	if( environment(me)!=me->query_temp("lineup/env") 
		|| me->is_ghost() )
	{
		message_vision(HIY"�����Ѿ����������󷨵�λ���ϣ��󷨽�ɢ��\n"NOR, me );
    	me->dismiss_lineup();
    	return 1;
	}


	if( !me->query_form() )
		return 1;

	lineup=me->query_lineup();

	if( arrayp(lineup) )
	{
		for( i = 0;i<sizeof(lineup);i++ )
		{
			if( !lineup[i] || environment(lineup[i])!=me->query_temp("lineup/env")
				|| lineup[i]->is_ghost() )
			{
				message_vision(HIY"��Ϊ���������󷨣��󷨵������ܵ�Ӱ�졣\n"NOR,me);
				if(lineup[i])
				{
					lineup[i]->set_lineup(0);
					lineup[i]->delete_form();
					lineup[i]->remove_lineup_effect();
				}
				lineup -= ( {lineup[i]} );
				i = 0;
			}
		}

		for( i=0;i<sizeof(lineup);i++)
			lineup -= ( {0} );

		for( i=0;i<sizeof(lineup);i++)
		{
			if( lineup[i] )
			{
				lineup[i]->set_lineup( lineup );
				lineup[i]->remove_lineup_effect();
				lineup[i]->apply_lineup_effect();
			}
		}

		if( me->is_fighting() )
		{
			enemy=me->query_enemy();
			message_vision( ( SKILL_D(me->query_form() ) )->query_action(),
				lineup[random(sizeof(lineup))],
				enemy[random(sizeof(enemy))] );
		}
	}

		
	call_out("check_lineup",1,me);

	return 1;
}


int help(object me)
{
    write(@HELP
��ָ��ʹ�÷���:

lineup form <��> - ��֯ĳ���󷨣�����󷨵�״ֻ̬Ҫһ�ƶ��ͻ�����
lineup with <ĳ��> - ��ĳ������󷨣��Լ���Է�������ĳ���󷨵������ߡ�
lineup dismiss     - �뿪�󷨡����´�ָ������󷨵�������, �������󷨻��ɢ��
lineup refuse      - �ܾ������󷨵����롣

ֱ���� lineup ָ��ʱ�����ʾ��Ŀǰ�Ƿ�����󷨼��󷨳�Ա������

HELP
    );
    return 1;
}
