void init()
{
   call_out("destroying", 30, this_object());  
   add_action("do_eat", "eat");      
}

void destroying(object me)
{
   if(environment(me)->query("name") != "ҩ¨"){
       message_vision("$NͻȻ�����ڵ��ϲ����ˡ�\n", me);       
       destruct(me);
       return;
       }
   else call_out("destroying", 30, this_object());
}

int do_eat(string arg)
{
        object me=this_player();

        if (!id(arg)) return notify_fail("�����ʲô��\n");

        if((int)me->query_condition("medicine") > 0){
            me->add("qi", -10);
            me->add("neili", 10);
            message_vision(HIR "$N����һ��$n��ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n"NOR, me, this_object());
            } 
        else{
            me->add("qi", 10);
            message_vision("$N����һ��$n��ֻ���û����������ڣ������ĺö��ˣ�\n", me, this_object());
            me->apply_condition("medicine", 10);
            }
        destruct(this_object());
        return 1;
}
