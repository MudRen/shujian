// tiezhang-xinfa.cÈ ÌúÕÆĞÄ·¨
inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        if( (int)me->query_skill("tiezhang-xinfa", 1) >= 200 )
             return notify_fail("Äã²»ÄÜÔÙÑ§Ï°ÌúÕÆĞÄ·¨ÁË¡£\n");
        return 1;
}
int practice_skill(object me)
{
        return notify_fail("ÌúÕÆĞÄ·¨Ö»ÄÜ¿¿Ñ§(learn)À´Ìá¸ß¡£\n");
}


