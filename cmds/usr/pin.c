inherit F_CLEAN_UP;

int main(object me, string arg)
{
   object ob;

   if( me != this_player(1) ) return 0;

   ob = me->query_temp("link_ob");
   if( !ob ) return 0;
   while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

   write("为了交易安全起见，请先输入您原来的PIN码：");
   input_to("get_old_pass", 1, ob);
   return 1;
}

private void get_old_pass(string pass, object ob)
{
   string old_pass;

   write("\n");
   old_pass = ob->query("security-code");
   if(!old_pass)
    write("您还未设定PIN码！\n");


   else if( crypt(pass, old_pass)!=old_pass ) {
     write("PIN码错误！\n");
     return;
   }
   write("请输入新的PIN码：");
   input_to("get_new_pass", 1, ob );
}

private void get_new_pass(string pass, object ob)
{
   write("\n请再输入一次新的PIN码：");
   input_to("confirm_new_pass", 1, ob, crypt(pass,0));
}

private void confirm_new_pass(string pass, object ob, string new_pass)
{
   write("\n");
   if( crypt(pass, new_pass)!=new_pass ) {
     write("对不起，您输入的PIN码并不相同，继续使用原来的PIN码。\n");
     return;
   }
   seteuid(getuid());
   if( !ob->set("security-code", new_pass) ) {
     write("PIN码变更失败！\n");
     return;
   }

   ob->save();
   write("PIN码变更成功。\n");
}

int help(object me)
{
   write(@HELP
指令格式 : pin
 
这个指令可以修改你的安全交易PIN密码。
 
HELP
    );
    return 1;
}
 