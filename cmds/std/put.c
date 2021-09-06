// put.c

inherit F_CLEAN_UP;

int do_put(object me, object obj, object dest);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string target, item;
        object obj, dest, *inv, obj2;
        int i, amount;

        if(!arg) return notify_fail("��Ҫ��ʲô�����Ž����\n");

        if( sscanf(arg, "%s in %s", item, target)!=2 )
                return notify_fail("��Ҫ��˭ʲô������\n");

        dest = present(target, me);
        if( !dest || living(dest)) dest = present(target, environment(me));
        if( !dest || living(dest))
                return notify_fail("����û������������\n");
        if(dest->is_character())
                return notify_fail("�㲻����������\n");
        if(dest->query("no_put"))
                return notify_fail("�㲻�ܰѶ��������\n");
        if(dest->query("no_unique"))
                return notify_fail("�㲻�ܰѱ�����������棡\n");
        if( !dest->query_max_encumbrance() )  
                return notify_fail("�ǲ���������\n");

                        
        if(sscanf(item, "%d %s", amount, item)==2) {
                if( !objectp(obj = present(item, me)) )
                        return notify_fail("������û������������\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "���ܱ��ֿ���\n");
                if( amount < 1 )
                        return notify_fail("����������������һ����\n");
                if( amount > obj->query_amount() )
                        return notify_fail("��û����ô���" + obj->name() + "��\n");
                if( obj->query("weapon_prop") && me->is_exert() &&
                        obj == me->query_temp("weapon"))
                               return notify_fail("������ʹ��"+me->query_exert()+"���޷�����"+obj->name()+"��\n");
                if( obj->query("weapon_prop") && me->is_perform() &&
                        obj == me->query_temp("weapon"))
                               return notify_fail("������ʹ��"+me->query_perform()+"���޷�����"+obj->name()+"��\n");
                 
                else if( amount == (int)obj->query_amount() )
                        return do_put(me, obj, dest);
                else {
                        obj->set_amount( (int)obj->query_amount() - amount );
                        if( obj->query("unique") ) {
                    		write("ͻȻ"+to_chinese(amount)+obj->query("unit")+obj->name()+"һ������Ȼʧȥ����Ӱ��\n");
                    		return 0;
                	}
                        obj2 = new(base_name(obj));
                        obj2->set_amount(amount);
                        obj2->set("broken", obj->query("broken"));
                        if (do_put(me, obj2, dest)) return 1;
                        obj2->move(me);
                        return 0;
                }
        }

        if(item=="all") {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++){
                        if(inv[i] == me->query_temp("weapon") && 
                          (me->query_exert() || me->query_perform())) continue;
                        if( inv[i] != dest ) do_put(me, inv[i], dest);
                        }
                write("Ok.\n");
                return 1;
        }
        if( !objectp(obj = present(item, me)) )
                return notify_fail("������û������������\n");
        if( !wizardp(me) && obj->query("no_drop") ) {
                if (stringp(obj->query("no_drop")))
                        return notify_fail(obj->query("no_drop"));
                return notify_fail("������������뿪�㱾��\n");
        }
        if (!wizardp(me) && obj->query("embedded"))
                 return notify_fail("������������ò�������\n");
        if( obj->query("weapon_prop") && me->is_exert() &&
            obj == me->query_temp("weapon"))
                 return notify_fail("������ʹ��"+me->query_exert()+"���޷�����"+obj->name()+"��\n");
        if( obj->query("weapon_prop") && me->is_perform() &&
            obj == me->query_temp("weapon"))
                 return notify_fail("������ʹ��"+me->query_perform()+"���޷�����"+obj->name()+"��\n");
                 
        return do_put(me, obj, dest);
}

int do_put(object me, object obj, object dest)
{
        if(obj->query("invisible") && !wizardp(me)) return 0;
        if (!wizardp(me) && obj->query("no_drop"))
                return notify_fail(stringp(obj->query("no_drop"))?
                        obj->query("no_drop"):"���������޷��뿪�㡣\n");
        if (!wizardp(me) && obj->query("embedded"))
                 return notify_fail("������������ò�������\n");

        if (obj == dest) return notify_fail("����Ž�������壿\n");
        if( obj->query("unique") ) {
        	message_vision("ֻ��һ"+obj->query("unit")+"$n�ѳ�$N����ʱһ������Ȼʧȥ����Ӱ��\n", me, obj);
        	destruct(obj);
                return 0;
        }
        if ( obj->move(dest) ) {
                message_vision( sprintf("$N��һ%s%s�Ž�%s��\n",
                        obj->query("unit"), obj->name(), dest->name()), me );
                return 1;
        }
        return 0;
}

int help(object me)
{
write(@HELP
ָ���ʽ : put <��Ʒ����> in <ĳ����>
 
���ָ��������㽫ĳ����Ʒ�Ž�һ����������Ȼ��������Ҫӵ��������Ʒ��
 
HELP
    );
    return 1;
}
