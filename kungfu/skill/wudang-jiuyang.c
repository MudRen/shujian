 inherit SKILL;
 void init();
 
 void create() { seteuid(getuid()); }
 
 string type() { return "martial"; }
 
 int valid_learn(object me)
 {
        return notify_fail("武当九阳功的诀窍只有自己从[九阳真经]中领悟！\n");
 }
 
 int practice_skill(object me)
 {
        return notify_fail("武当九阳功的诀窍只有自己从[九阳真经]中领悟！\n");
 }
