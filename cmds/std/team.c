// team.c
// form_array ʲô������

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object *t;
    string msg;

    if( !arg ) {
        if( !pointerp(t = me->query_team()) )
            return notify_fail("�����ڲ�û�вμ��κζ��顣\n");
        write("�����ڶ����еĳ�Ա�У�\n  " + implode(t->name(1), "\n  ") + "��\n");
        return 1;
    }
    if( arg=="dismiss" ) {
        if( !pointerp(t = me->query_team()) )
            return notify_fail("�����ڲ�û�вμ��κζ��顣\n");
        if( me->is_team_leader() ) {
            message("team", me->name(1) + "�������ɢ�ˡ�\n", t, me);
            write("�㽫�����ɢ�ˡ�\n");
        } else {
            message("team", me->name(1) + "����������顣\n", t, me);
            write("����������Ķ��顣\n");
        }
        me->dismiss_team();
        return 1;
    }
    if( sscanf(arg, "with %s", arg)==1 ) {
        object ob;

        if( !(ob = present(arg, environment(me)))
          || !living(ob)
          || !ob->is_character()
          || ob==me )
            return notify_fail("�����˭��Ϊ��飿\n");

        if( ob->query_condition("killer") && ! me->query_condition("killer"))
            return notify_fail("�Է����ڱ��ٸ�ͨ�������ܼ�����Ķ��顣\n");

        if( !pointerp(me->query_team()) || me->is_team_leader() ) {
            if( me==(object)ob->query_temp("pending/team") ) {
                if( !pointerp(me->query_team()) ) {
                    ob->add_team_member(me);
                    message_vision("$N��������$n�Ķ��顣\n", me, ob);
                } else {
                    me->add_team_member(ob);
                    message_vision("$N������$n������顣\n", me, ob);
                }
                ob->delete_temp("pending/team");
                return 1;
            } else {
                message_vision("$N����$n����$P�Ķ��顣\n", me, ob);
                tell_object(ob, YEL "�����Ը����룬���� team with " + me->query("id") + "��\n" NOR);
                me->set_temp("pending/team", ob);
                return 1;
            }
        } else
            return notify_fail("ֻ�ж����������������˼��롣\n");
    }
    if( sscanf(arg, "talk* %s", arg)==1 ) {
        string vb, emote_arg;
        if( !pointerp(t=me->query_team()) )
            return notify_fail("�����ڲ�û�кͱ�����ɶ��顣\n");
        if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 )
        {
            vb = arg;
            emote_arg = "";
        }
        if (!(msg = EMOTE_D->do_emote(me, vb, emote_arg, 1, me->name())))
            return notify_fail("������ʲô��\n");
        message("team", HIW "�����顿" + msg + "\n" + NOR, t);
        return 1;
    }
    else if( sscanf(arg, "talk %s", arg)==1 ) {
        if( !pointerp(t=me->query_team()) )
            return notify_fail("�����ڲ�û�кͱ�����ɶ��顣\n");
        message("team", HIW "�����顿" + me->query("name") + "(" + capitalize(me->query("id")) + ")��" + arg + "\n" NOR, t);
        return 1;
    }
    
    else if( sscanf(arg, "kickout %s", arg)==1 ) {
    	if( pointerp(t = me->query_team()) && me->is_team_leader() ) {
    		object tar;
    		if(arg==getuid(me)) return notify_fail("���Լ���YOU ARE BEAUTIFUL��\n");
    		if(!objectp(tar = find_player(arg))) return notify_fail("��Ҫ��˭�뿪���飿\n");
    		if(member_array(tar,t)==-1) return notify_fail(tar->query("name")+"������Ķ����\n");
    		tar->dismiss_team();
    		tell_object(tar,me->name(1)+"�����߳��˶��顣\n");
    		message("team", me->name(1) + "��"+tar->query("name")+"�߳��˶��顣\n", t, ({me,tar}));
            	write("���"+tar->query("name")+"�߳��˶��顣\n");
            	t = me->query_team();
            	if(sizeof(t)<=1)
            	{
            		me->dismiss_team();
            		write("��Ϊû���κζ��ѣ���Ķ����ɢ�ˡ�\n");
            	}
            	return 1;
	}
	else return notify_fail("ֻ�ж�������������ˡ�\n");	
    }
    /*
    if( sscanf(arg, "form %s", arg)==1 ) {
        if( !pointerp(t=me->query_team()) || !me->is_team_leader() )
            return notify_fail("�������һ����������������֯���Ρ�\n");
        if( !me->query_skill(arg, 1) )
            return notify_fail("����������ûѧ����\n");
        return SKILL_D(arg)->form_array(me);
    }
    */
}

int help(object me)
{
//team form <��> - ������������ѧ���󷨵Ļ������Խ������еĳ�Ա��֯��
  //                 ĳ�����Σ�������ε�״ֻ̬Ҫ����һ�ƶ��ͻ�����
	write(@HELP
����ָ��ʹ�÷���:

team with <ĳ��>      - ��ĳ����ɶ���. ����Ҫ˫����ͬ�����Ż���Ч��
team kickout <ĳ��>   - ��ĳ���߳����飬ֻ���������á�
team dismiss          - �뿪����. ���´�ָ���������, ������������ɢ��
team talk <ѶϢ>      - ����������������̸��, ������ tt <ѶϢ> �����

ֱ���� team ָ��ʱ�����ʾ��Ŀǰ�Ƿ��м�����鼰��Ա������

ע: team �� follow �Ƕ����ģ��㲻һ��Ҫ follow ��������䡣
HELP
    );
    return 1;
}
