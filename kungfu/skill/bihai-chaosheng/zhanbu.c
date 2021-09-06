// Modified by Darken@SJ
#include <ansi.h>
inherit F_CLEAN_UP;

string exert_name() { return HIG"����ռ����"NOR; }

int exert(object me, mixed arg)
{
        object ob;
        int i;
        
        if(!arg)
                return notify_fail("��ʽ��exert zhanbu <id>| help <id> \n"); 
        if( objectp(arg) )
                return notify_fail("��Ҫ�ҵ��˾���һ�ԣ�����ռ������ʲô��\n"); 
        if( !stringp(arg) )
                return notify_fail("��Ҫ��ռ����˭��\n"); 
        if( me->query("zhanbu") )
                return notify_fail("������ռ���ء�\n");
        if( sscanf(arg,"help %s", arg) == 1)
                i = 1;
        if( me->query("id") == arg )
                return notify_fail("���Լ��ö˶˵ģ����Ƿ����ˣ�\n");
        if( !wizardp(me) && me->query("family/family_name") != "�һ���" )
                return notify_fail("�㲻���һ������ӣ�δ�û�ҩʦ�洫������ܹ�ռ����\n");
        if( !wizardp(me) && (int)me->query("family/generation") < 2 )
                return notify_fail("�㱲�ֹ��ͣ�δ�û�ҩʦ�洫������ܹ�ռ����\n");
        if( (int)me->query_skill("qimen-bagua", 1) < 100 )
                return notify_fail("�㻹��֪������ռ���ء�\n");
        if( me->query("neili") < 2000 )
                return notify_fail("����������������ܹ�ռ����\n");
        if( !present("tie bagua", me) )
                return notify_fail("����Ҫһö�����Բ���ռ����\n");
                
        if(i) {
                if(!objectp(ob = present(arg, environment(me))))
                        return notify_fail("����û������ˡ�\n");
                if( !ob->is_character() || ob->is_corpse() )
                        return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
                if( !ob->query_temp("zhanbu") )
                        return notify_fail(ob->name()+"û����ռ�����������æ��\n");
                if( stringp(ob->query_temp("zhanbu")) )
                        return notify_fail("�Ѿ����˰���"+ob->name()+"ռ���ˡ�\n");
                ob->set_temp("zhanbu", me->query("id") );
                message_vision(HIG"$N���������֣��������������$n�İٻ��Ѩ֮�ϣ�\n", me, ob);
                tell_object(ob, "�����"+me->name()+"���������ϴ�����ͷ���еľ���һ���������˲��٣�\n");
                me->start_busy(5);
        } else {
                i = ABS(35-(me->query("int")));
                me->set_temp("zhanbu", 1);
                message_vision(HIG"$N������ָ�������ӡ�������î�������ȡ��硢δ���ꡢ�ϡ��硢���ķ�λ����ϸ�������š�����\n"NOR, me);
                call_out("check_target", i, me, arg);
                me->start_busy(i);
        }
        return 1;
}

int check_target(object me, string arg)
{
        int i, help = 1;
        object ob, where;
        string str;
        
        if( !me ) return 0;
        if( stringp(me->query_temp("zhanbu")) )
                help = 2;
        me->delete_temp("zhanbu");
        if( !living(me) || me->is_fighting() ) return 0;
        me->start_busy(1);
        i = me->query("max_neili") / 2;
        if( i < 2000 ) i = 2000;
        me->receive_damage("neili", i, "�������Ĵ�����");
        ob = find_player(arg);
        if( !ob ) ob = find_living(arg);
        if( !ob || !me->visible(ob) || ob->query("no_quest") ) 
                tell_object(me, "�㷢��Ŀǰû��������ߡ�\n");
        else if ( wizardp(ob) )
                tell_object(me, "���޷�ͨ��ռ��֪����ʦ��λ�á�\n");
        else if( me->query("jingli") < ob->query_int() * 10 )
                tell_object(me, "�����ɥ�ط��������ڵľ�����������Է���λ�á�\n");
        else if ( !objectp(where = environment(ob)) ) 
                tell_object(me, HIW"������ôҲ�㲻�������������Ү...\n"NOR);
        else if( random(me->query("kar")) * help < ob->query("kar") ){
                tell_object(me, HIY"��������˰��������������ռ������"+ob->name(1)+"��λ�á�\n"NOR);
                me->add("jingli", -ob->query_skill("force"));
                me->start_busy(2);
        } else {
                if( random((int)me->query_int()) * help < (int)ob->query_int()/2 )
                        tell_object(ob, HIY"ڤڤ������ú����������ڿ�̽�����ڵķ�λ��\n"NOR);
                str = TASK_D->get_regions(base_name(where));
                if( str == "" )
                        str = "��ԭ";
                if( help == 2 && stringp(where->query("short")) )
                        str += where->query("short");
                tell_object(me, sprintf(HIW"����ָ���%s(%s)���ں�����%s"HIW"һ�����\n"NOR,
                        (string)ob->name(1) ,capitalize((string)ob->query("id")) ,str));
                me->add("jingli", -ob->query_skill("force")*2);
                me->start_busy(2);
        }
        return 1;
}

int help(object me)
{
        write(HIG"\n������ռ��������"NOR"\n");
        write(@HELP

        ʹ�����Ű��Եļ��ɣ�ռ��һ���˵�����λ�á�����һ������ͬʱռ������
        �Ӽ����ٶ��Լ��ɹ����ᡣ

        Ҫ��  �̺������ȼ� 100 ���ϣ�
                ���Ű��Եȼ� 100 ���ϣ�
                ������� 2000 ���ϣ�
                ����Ϊ��ҩʦ�״����ӡ�
HELP
        );
        return 1;
}

