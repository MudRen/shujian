// qu.h
int do_haha(object ob, object obj);
int do_qu(string arg)
{
        string arg1, arg2;
        object obj, *inv, env, obj2;
        object me = this_object();
        object ob = this_player();
        int i, amount;
        if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
                return notify_fail("����û������������\n");

        if (arg2!="lu")
                return notify_fail("����û������������\n");

        if( !me->query("marks/open") )
        return notify_fail("��¯�ĸ���û�д򿪡�\n");
                
        if( ob->is_busy() )
                return notify_fail("������æ��\n");

        if( sscanf(arg, "%s from %s", arg, arg1)==2 ) {
                env = present(arg1, ob);
                if(!env) env = present(arg1, environment(ob));
                if(!env) return notify_fail("���Ҳ��� " + arg1 + " ����������\n");
                if(living(env) && (wiz_level(me) <= wiz_level(env)))
                        return notify_fail("�����ʦ�ȼ�����ȶԷ��ߣ���������\n");
        } else env = environment(ob);
        if (!wizardp(me) && env->query("no_get_arg1"))
                return notify_fail("���컯�յ������ٰ���\n");

        if(sscanf(arg, "%d %s", amount, arg1)==2) {
                if( !objectp(obj = present(arg1, env)) )
                        return notify_fail("����û������������\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "���ܱ��ֿ����ߡ�\n");
                if( amount < 1 )
                        return notify_fail("�����ĸ���������һ����\n");
                if( amount > obj->query_amount() )
                        return notify_fail("����û����ô���" + obj->name() + "��\n");
                else if( amount == (int)obj->query_amount() ) {
                        return do_haha(ob, obj);
                } else {
                        obj2 = new(base_name(obj));
                        obj2->set_amount( obj->query_amount() - amount);
                        obj->set_amount( amount );

                        if( ob->is_fighting() ) ob->start_busy(3);
                        if (do_haha(ob, obj)) {
                                obj2->move(env);
                                return 1;
                        }
                        obj2->move(env);
                        return 0;
                }
        }

        if(arg=="all") {
                if( ob->is_fighting() ) return notify_fail("�㻹��ս���У�ֻ��һ����һ����\n");
                if( !env->query_max_encumbrance() )     return notify_fail("�ǲ���������\n");

                inv = all_inventory(env);
                if( !sizeof(inv) )
                        return notify_fail("������û���κζ�����\n");

                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i]->is_character() || inv[i]->query("no_get") ) continue;
                        do_haha(ob, inv[i]);
                }
                write("Ok��\n");
                return 1;
        }

        if( !objectp(obj = present(arg, env)) || living(obj) )
                return notify_fail("�㸽��û������������\n");

        if( !wizardp(ob) && obj->query("no_get") ) {
                if (stringp(obj->query("no_get")))
                        return notify_fail(obj->query("no_get"));
                return notify_fail("��������ò�������\n");
        }
        
        return do_haha(ob, obj);
}
        
int do_haha(object ob, object obj)
{
        object old_env;
        int equipped;

        if( !obj ) return 0;
        old_env = environment(obj);

        if( obj->is_character() ) {
                if( living(obj) ) return 0;
        } else {
                if( !wizardp(ob) && obj->query("no_get") ) return 0;
        }

        if( obj->query("equipped") ) equipped = 1;
        if( obj->move(ob) ) {
                if( ob->is_fighting() ) ob->start_busy(1);
                if( obj->is_character() )
                        message_vision( "$N��$n�����������ڱ��ϡ�\n", ob, obj );
                else
                        message_vision( sprintf("$N%sһ%s$n��\n", 
                                old_env==environment(ob)? "����":
                                        (old_env->is_character() ?
                                                "��" + old_env->name() + "����" + (equipped? "����" : "�ѳ�"):
                                                "��" + old_env->name() + "���ó�"),
                                obj->query("unit")), ob, obj);
                ob->start_busy(90);
                return 1;
        }
        else return 0;
}
